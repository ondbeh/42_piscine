#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype of ft_strjoin
char *ft_strjoin(int size, char **strs, char *sep);

int main(void)
{
    // Test case 1: Multiple strings with a space separator
    char *strs1[] = {"Hello", "World", "42"};
    char *sep1 = " ";
    char *result1 = ft_strjoin(3, strs1, sep1);
    printf("Test 1: %s\n", result1); // Expected: "Hello World 42"

    // Test case 2: Single string (no separator should be added)
    char *strs2[] = {"OnlyOne"};
    char *sep2 = "-";
    char *result2 = ft_strjoin(1, strs2, sep2);
    printf("Test 2: %s\n", result2); // Expected: "OnlyOne"

    // Test case 3: No strings (size is 0, should return an empty string)
    char *strs3[] = {};
    char *sep3 = ",";
    char *result3 = ft_strjoin(0, strs3, sep3);
    printf("Test 3: %s\n", result3); // Expected: ""

    // Test case 4: Empty strings with a comma separator
    char *strs4[] = {"", "", ""};
    char *sep4 = ",";
    char *result4 = ft_strjoin(3, strs4, sep4);
    printf("Test 4: %s\n", result4); // Expected: ",,"

    // Test case 5: Mixed empty and non-empty strings with a dash separator
    char *strs5[] = {"First", "", "Third", "Fourth"};
    char *sep5 = "";
    char *result5 = ft_strjoin(4, strs5, sep5);
    printf("Test 5: %s\n", result5); // Expected: "First--Third"

    // Free allocated memory
    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);

    return 0;
}

// while (**strs)
// 		{
// 			*ret_tmp = **strs;
// 			++ret_tmp;
// 			++(*strs);
// 		}
// 		while (*sep_tmp && size > 0)
// 		{
// 			*ret_tmp = *sep_tmp;
// 			++ret_tmp;
// 			++sep_tmp;
// 		}
// 		sep_tmp = sep;