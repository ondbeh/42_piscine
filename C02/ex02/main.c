#include <stdio.h>

int ft_str_is_alpha(char *str);

int main(void){
    char string1[] = "Hello World!!";
    char string2[] = "FYou";
    char string3[] = "";
    char string4[] = " ";

    printf("1: %d, 2: %d, 3: %d, 4: %d\n", ft_str_is_alpha(string1), ft_str_is_alpha(string2),
                                            ft_str_is_alpha(string3), ft_str_is_alpha(string4));
    return 0;


}