#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Prototype of ft_strdup
char *ft_strdup(char *src);

// Main function to test ft_strdup
int main(void)
{
    char *src1 = "Hello, World!";
    char *src2 = "";
    char *src3 = "This is a longer string to test the strdup function.";
    char *src4 = "1234567890";
    char *src5 = NULL;

    char *dup1 = ft_strdup(src1);
    char *dup2 = ft_strdup(src2);
    char *dup3 = ft_strdup(src3);
    char *dup4 = ft_strdup(src4);
    char *dup5 = ft_strdup(src5);

    // Print results for each test case
    if (dup1 != NULL)
        printf("Original: %s\nDuplicate: %s\n\n", src1, dup1);
    else
        printf("dup1 returned NULL\n\n");

    if (dup2 != NULL)
        printf("Original: \"%s\"\nDuplicate: \"%s\"\n\n", src2, dup2);
    else
        printf("dup2 returned NULL\n\n");

    if (dup3 != NULL)
        printf("Original: %s\nDuplicate: %s\n\n", src3, dup3);
    else
        printf("dup3 returned NULL\n\n");

    if (dup4 != NULL)
        printf("Original: %s\nDuplicate: %s\n\n", src4, dup4);
    else
        printf("dup4 returned NULL\n\n");

    if (dup5 != NULL)
        printf("Original: %s\nDuplicate: %s\n\n", src5, dup5);
    else
        printf("dup5 returned NULL (expected)\n\n");

    // Free allocated memory
    free(dup1);
    free(dup2);
    free(dup3);
    free(dup4);
    free(dup5);

    return 0;
}