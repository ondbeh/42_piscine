#include <stdio.h>
#include <string.h>

// Function declaration
char	*ft_strncat(char *dest, char *src, unsigned int nb);

// Main function to test ft_strncat
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
    unsigned int test1_nb = 3;

    char *test2_src = "";
    unsigned int test2_nb = 5;

    char *test3_src = "nonempty";
    unsigned int test3_nb = 4;

    char *test4_src = "def";
    unsigned int test4_nb = 2;

    char *test5_src = "67890";
    unsigned int test5_nb = 5;

    char *test6_src = "ing";
    unsigned int test6_nb = 1;

    char *test7_src = "Case";
    unsigned int test7_nb = 2;

    char *test8_src = "enation";
    unsigned int test8_nb = 4;

    char *test9_src = "Case";
    unsigned int test9_nb = 4;

    char *test10_src = "123";
    unsigned int test10_nb = 2;

    // Testing and printing the results
    printf("Test 1: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer1, test1_src, test1_nb, ft_strncat(buffer1, test1_src, test1_nb)); // Expected output: "hello wo"
    printf("Test 2: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer2, test2_src, test2_nb, ft_strncat(buffer2, test2_src, test2_nb)); // Expected output: "hello"
    printf("Test 3: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer3, test3_src, test3_nb, ft_strncat(buffer3, test3_src, test3_nb)); // Expected output: "none"
    printf("Test 4: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer4, test4_src, test4_nb, ft_strncat(buffer4, test4_src, test4_nb)); // Expected output: "abcdef"
    printf("Test 5: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer5, test5_src, test5_nb, ft_strncat(buffer5, test5_src, test5_nb)); // Expected output: "1234567890"
    printf("Test 6: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer6, test6_src, test6_nb, ft_strncat(buffer6, test6_src, test6_nb)); // Expected output: "Testing"
    printf("Test 7: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer7, test7_src, test7_nb, ft_strncat(buffer7, test7_src, test7_nb)); // Expected output: "UpperCa"
    printf("Test 8: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer8, test8_src, test8_nb, ft_strncat(buffer8, test8_src, test8_nb)); // Expected output: "concaten"
    printf("Test 9: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer9, test9_src, test9_nb, ft_strncat(buffer9, test9_src, test9_nb)); // Expected output: "edgeCase"
    printf("Test 10: \"%s\" + \"%s\" (nb = %d) => \"%s\"\n", buffer10, test10_src, test10_nb, ft_strncat(buffer10, test10_src, test10_nb)); // Expected output: "edgecase12"

    return 0;
}