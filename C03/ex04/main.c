#include <stdio.h>

// Function declaration
char *ft_strstr(char *str, char *to_find);

int main() {
    // Test cases
    char str1[] = "Hello, world!";
    char to_find1[] = "world";
    
    char str2[] = "Hello, world!";
    char to_find2[] = "hello";

    char str3[] = "Hello, world!";
    char to_find3[] = "";

    char str4[] = "Hello, world!";
    char to_find4[] = "Hello, world!";

    char str5[] = "Hello, world!";
    char to_find5[] = "world!";

    char str6[] = "Hello, world!";
    char to_find6[] = "Hello, world! ";
    
    // Testing ft_strstr
    char *result;

    result = ft_strstr(str1, to_find1);
    if (result != NULL)
        printf("Test 1: Found '%s' in '%s' at position: %ld\n", to_find1, str1, result - str1);
    else
        printf("Test 1: '%s' not found in '%s'\n", to_find1, str1);

    result = ft_strstr(str2, to_find2);
    if (result != NULL)
        printf("Test 2: Found '%s' in '%s' at position: %ld\n", to_find2, str2, result - str2);
    else
        printf("Test 2: '%s' not found in '%s'\n", to_find2, str2);

    result = ft_strstr(str3, to_find3);
    if (result != NULL)
        printf("Test 3: Found '%s' in '%s' at position: %ld\n", to_find3, str3, result - str3);
    else
        printf("Test 3: '%s' not found in '%s'\n", to_find3, str3);

    result = ft_strstr(str4, to_find4);
    if (result != NULL)
        printf("Test 4: Found '%s' in '%s' at position: %ld\n", to_find4, str4, result - str4);
    else
        printf("Test 4: '%s' not found in '%s'\n", to_find4, str4);

    result = ft_strstr(str5, to_find5);
    if (result != NULL)
        printf("Test 5: Found '%s' in '%s' at position: %ld\n", to_find5, str5, result - str5);
    else
        printf("Test 5: '%s' not found in '%s'\n", to_find5, str5);

    result = ft_strstr(str6, to_find6);
    if (result != NULL)
        printf("Test 6: Found '%s' in '%s' at position: %ld\n", to_find6, str6, result - str6);
    else
        printf("Test 6: '%s' not found in '%s'\n", to_find6, str6);

    return 0;
}
