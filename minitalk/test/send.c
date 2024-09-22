#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void send_char_as_signals(int pid, char c) {
    for (int i = 7; i >= 0; i--) {
        // 判断字符 c 的二进制第 i 位是 0 还是 1
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);  // 如果是1，发送 SIGUSR2
        else
            kill(pid, SIGUSR1);  // 如果是0，发送 SIGUSR1
        usleep(100);  // 休眠一段时间，以避免信号过快发送
    }
}

int main(int argc, char **argv)
{
    int i = 0;


    if (argc == 2 && !argv)
    {
        
    }
    else 
        printf("please follow:./exe pid string.\n");
    return 0;
}