#include <stdio.h>
#include <string.h> // For comparing with standard strlcpy

// Function prototype for ft_strlcpy
size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);

int main() {
    char src[] = "Hello, World!";
    char dest1[20];
    char dest2[20];
    size_t result1, result2;

    // Test 1: Normal case
    result1 = ft_strlcpy(dest1, src, sizeof(dest1));
    result2 = strlcpy(dest2, src, sizeof(dest2)); // For comparison

    printf("Test 1 - Normal case:\n");
    printf("Source: %s\n", src);
    printf("Destination (ft_strlcpy): %s\n", dest1);
    printf("Destination (strlcpy): %s\n", dest2);
    printf("Return value (ft_strlcpy): %zu\n", result1);
    printf("Return value (strlcpy): %zu\n\n", result2);

    // Test 2: dstsize smaller than src length
    result1 = ft_strlcpy(dest1, src, 5);
    result2 = strlcpy(dest2, src, 5);

    printf("Test 2 - dstsize smaller than src length:\n");
    printf("Source: %s\n", src);
    printf("Destination (ft_strlcpy): %s\n", dest1);
    printf("Destination (strlcpy): %s\n", dest2);
    printf("Return value (ft_strlcpy): %zu\n", result1);
    printf("Return value (strlcpy): %zu\n\n", result2);

    // Test 3: dstsize is 0
    result1 = ft_strlcpy(dest1, src, 0);
    result2 = strlcpy(dest2, src, 0);

    printf("Test 3 - dstsize is 0:\n");
    printf("Source: %s\n", src);
    printf("Destination (ft_strlcpy): %s\n", dest1);
    printf("Destination (strlcpy): %s\n", dest2);
    printf("Return value (ft_strlcpy): %zu\n", result1);
    printf("Return value (strlcpy): %zu\n\n", result2);

    // Test 4: Empty source string
    char src_empty[] = "";
    result1 = ft_strlcpy(dest1, src_empty, sizeof(dest1));
    result2 = strlcpy(dest2, src_empty, sizeof(dest2));

    printf("Test 4 - Empty source string:\n");
    printf("Source: %s\n", src_empty);
    printf("Destination (ft_strlcpy): %s\n", dest1);
    printf("Destination (strlcpy): %s\n", dest2);
    printf("Return value (ft_strlcpy): %zu\n", result1);
    printf("Return value (strlcpy): %zu\n\n", result2);

    return 0;
}
