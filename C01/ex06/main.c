#include "ft_strlen.c"
#include <stdio.h>


int ft_strlen (char *str);

int main(void)
{
    char *str;

    str = "Hello World";

    int j = ft_strlen(str);

    printf("%d\n", j);

    return 0;
}