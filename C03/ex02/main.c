#include <stdio.h>
#include <string.h>

// Function declaration
char	*ft_strcat(char *dest, char *src);

// Main function to test ft_strcat
int main(void)
{
    // Test case buffers
    char buffer1[50] = "hello";
    char buffer2[50] = "hello";
    char buffer3[50] = "";
    char buffer4[50] = "abc";
    char buffer5[50] = "12345";
    char buffer6[50] = "Test";
    char buffer7[50] = "Upper";
    char buffer8[50] = "concat";
    char buffer9[50] = "edge";
    char buffer10[50] = "edgecase";

    // Test cases
    char *test1_src = " world";
    char *test2_src = "";
    char *test3_src = "nonempty";
    char *test4_src = "def";
    char *test5_src = "67890";
    char *test6_src = "ing";
    char *test7_src = "Case";
    char *test8_src = "enation";
    char *test9_src = "Case";
    char *test10_src = "123";

    // Testing and printing the results
    printf("Test 1: \"%s\" + \"%s\" => \"%s\"\n", buffer1, test1_src, ft_strcat(buffer1, test1_src)); // Expected output: "hello world"
    printf("Test 2: \"%s\" + \"%s\" => \"%s\"\n", buffer2, test2_src, ft_strcat(buffer2, test2_src)); // Expected output: "hello"
    printf("Test 3: \"%s\" + \"%s\" => \"%s\"\n", buffer3, test3_src, ft_strcat(buffer3, test3_src)); // Expected output: "nonempty"
    printf("Test 4: \"%s\" + \"%s\" => \"%s\"\n", buffer4, test4_src, ft_strcat(buffer4, test4_src)); // Expected output: "abcdef"
    printf("Test 5: \"%s\" + \"%s\" => \"%s\"\n", buffer5, test5_src, ft_strcat(buffer5, test5_src)); // Expected output: "1234567890"
    printf("Test 6: \"%s\" + \"%s\" => \"%s\"\n", buffer6, test6_src, ft_strcat(buffer6, test6_src)); // Expected output: "Testing"
    printf("Test 7: \"%s\" + \"%s\" => \"%s\"\n", buffer7, test7_src, ft_strcat(buffer7, test7_src)); // Expected output: "UpperCase"
    printf("Test 8: \"%s\" + \"%s\" => \"%s\"\n", buffer8, test8_src, ft_strcat(buffer8, test8_src)); // Expected output: "concatenation"
    printf("Test 9: \"%s\" + \"%s\" => \"%s\"\n", buffer9, test9_src, ft_strcat(buffer9, test9_src)); // Expected output: "edgeCase"
    printf("Test 10: \"%s\" + \"%s\" => \"%s\"\n", buffer10, test10_src, ft_strcat(buffer10, test10_src)); // Expected output: "edgecase123"

    return 0;
}