#include<stdio.h>

char *ft_strcpy(char *dest, char *src);

int main(void)
{
    char src_str[] = "C programming language";
    char dst_str[1];
    printf("dst_str: %s\n", ft_strcpy(dst_str, src_str));
}