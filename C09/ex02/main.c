#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *str, char *charset);

int main(void) {
    char **result;
    char *str = "Hello--world--this-is-a-test";
    char *charset = "-";
    
    result = ft_split(str, charset);

    printf("Testing with string: \"%s\" and charset: \"%s\"\n", str, charset);
    for (int i = 0; result[i] != NULL; i++) {
        printf("Result[%d]: %s\n", i, result[i]);
        //free(result[i]);  // Free each string
    }
    free(result);  // Free the array

    // Add more test cases
    char *str2 = "Another|test|string|split";
    char *charset2 = "ts";
    
    result = ft_split(str2, charset2);

    printf("\nTesting with string: \"%s\" and charset: \"%s\"\n", str2, charset2);
    for (int i = 0; result[i] != NULL; i++) {
        printf("Result[%d]: %s\n", i, result[i]);
        //free(result[i]);
    }
    free(result);

    return 0;
}
