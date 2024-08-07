#include "ft_printf.h"
#include <limits.h>


// // %c
// int main()
// {
//     char c = 'z';

//     int i = ft_printf("%c\n", c);
//     printf("my:%d\n", i);
//     int j = printf("%c\n", c);
//     printf("ori:%d\n", j);

//     return 0;
// }

// // %p
// int main()
// {
//     int s = 122;

//     int i = ft_printf("my: %p\n", s);
//     printf("%d\n", i);
//     int j = printf("ori: %p\n", s);
//     printf("%d\n", j);

//     return 0;
// }

// // %s
// int  main()
// {
//     char *s = NULL;

//     int i = ft_printf("%s\n", s);
//     printf("my:%d\n", i);
//     int j = printf("%s\n", s);
//     printf("ori:%d\n", j); 

//     return 0;
// }

// // %d
// int main()
// {
//     int num = -42;
//     // int num = -2147483648;
//     // int num = 2147483647;

//     int i = ft_printf("%d\n", num);
//     printf("my:%d\n", i);
//     int j = printf("%d\n", num);
//     printf("ori:%d\n", j);

//     return 0;
// }

// // %i
// int main()
// {
//     // int num = 12;
//     int num = -2147483648;
//     // int num = 2147483647;

//     int i = ft_printf("%i\n", num);
//     printf("my:%d\n", i);
//     int j = printf("%i\n", num);
//     printf("ori:%d\n", j);

//     return 0;
// }

// // %u
// int main()
// {
//     // unsigned int d = 123;
//     unsigned int d = 4294967295;

//     int i = ft_printf("%u\n", d);
//     printf("my:%d\n", i);

//     int j = printf("%u\n", d);
//     printf("ori:%d\n", j);
    
//     return 0;
// }


// // %x %X
// int main()
// {
//     // unsigned int d = 0;
//     unsigned int d = 2147483647;
//     // unsigned int d = 4294967295;

//     int i = ft_printf("%x\n%X\n", d, d);
//     printf("my:%d\n", i);
//     int j = printf("%x\n%X\n", d, d);
//     printf("ori:%d\n", j);

//     return 0;
// }

// int main()
// {
//     unsigned int u = 4294967295;
//     char s[] = "string";

//     int i = ft_printf("c:%c\nd:%d\ni:%i\ns:%s\nu:%u\nx:%x\nX:%X\n", 'c', 1, 2, s, u, 12, 12);
//     printf("my:%d\n\n", i);
//     int j = printf("c:%c\nd:%d\ni:%i\ns:%s\nu:%u\nx:%x\nX:%X\n", 'c', 1, 2, s, u, 12, 12);
//     printf("ori:%d\n", j);

//     return 0;
// }

// %p
int main()
{
    // int c = 30000;
    // int *p;
    // p = &c;

    void *void_p = NULL;

    printf("%p\n", void_p);

    int j = ft_printf("%p\n", void_p);
    printf("%d\n", j);
    // int i = ft_printf("%p\n", p);
    // printf("%d\n", i);
    // int i1 = ft_printf("%p\n", &c);
    // printf("%d\n", i1);
    // int i2 = ft_printf("%d\n", *p);
    // printf("%d\n\n", i2);

    // int j = printf("%p\n", p);
    // printf("%d\n", j);
    // int j1 = printf("%p\n", &c);
    // printf("%d\n", j1);
    // int j2 = printf("%d\n", *p);
    // printf("%d\n", j2);

    return 0;
}