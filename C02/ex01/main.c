#include <stdio.h>

char    *ft_strncpy(char *dest, char *src, unsigned int n);

int main(void){
    char destString[] = "Hello World!!";
    char srcString[] = "F You";

    ft_strncpy( destString, srcString, 3 );

    printf("%s\n", destString);
    return 0;


}