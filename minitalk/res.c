#include <signal.h>
#include <stdio.h>
#include <unistd.h>

char signal_handler(int signal) {
    static int bit_count = 0;  // 记录当前接收到的位数
    static char c = 0;         // 存储正在重建的字符
    char cc;

    if (signal == SIGUSR1)
        c = (c << 1);  // 接收到 0，把 c 左移并不改变最低位
    else if (signal == SIGUSR2)
        c = (c << 1) | 1;  // 接收到 1，把 c 左移并将最低位设置为 1

    bit_count++;

    if (bit_count == 8) {  // 如果接收了8位，说明一个字符接收完毕
        cc = c;
        bit_count = 0;  // 重置位数计数器
        c = 0;          // 重置字符存储
        return cc;
    }
}

void pc(int signal)
{
    printf("%c\n", signal_handler(signal));
}
int main() {
    struct sigaction sa;
    sa.sa_flags = SA_RESTART;
    sa.sa_handler = signal_handler;

    // 设置信号处理器
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("pid:%d\n服务器正在运行,等待信号...\n", getpid());

    // 无限循环等待信号
    while (1)
        pause();

    return 0;
}
