#include <stdio.h>

// Function declaration
unsigned int ft_strlcat(char *dest, const char *src, unsigned int size);

int main() {
    // Test cases
    char dest1[20] = "Hello";
    char src1[] = " World";
    unsigned int size1 = sizeof(dest1);
    unsigned int result1;

    char dest2[10] = "Hello";
    char src2[] = "World";
    unsigned int size2 = sizeof(dest2);
    unsigned int result2;

    char dest3[20] = "";
    char src3[] = "Hello, World!";
    unsigned int size3 = sizeof(dest3);
    unsigned int result3;

    char dest4[6] = "Hi";
    char src4[] = " There";
    unsigned int size4 = sizeof(dest4);
    unsigned int result4;

    // Running tests
    result1 = ft_strlcat(dest1, src1, size1);
    printf("Test 1: dest = '%s', result = %u\n", dest1, result1);

    result2 = ft_strlcat(dest2, src2, size2);
    printf("Test 2: dest = '%s', result = %u\n", dest2, result2);

    result3 = ft_strlcat(dest3, src3, size3);
    printf("Test 3: dest = '%s', result = %u\n", dest3, result3);

    result4 = ft_strlcat(dest4, src4, size4);
    printf("Test 4: dest = '%s', result = %u\n", dest4, result4);

    return 0;
}