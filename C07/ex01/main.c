#include <stdio.h>
#include <stdlib.h>

#include "ft_range.c"

void print_array(int *arr, int size)
{
    if (arr == NULL)
    {
        printf("Array is NULL\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int *range1;
    int *range2;
    int *range3;
    int *range4;
    int *range5;

    // Test case 1: Normal range
    int min1 = 1;
    int max1 = 5;
    range1 = ft_range(min1, max1);
    printf("Range from %d to %d: ", min1, max1);
    print_array(range1, max1 - min1);

    // Test case 2: No range (min >= max)
    int min2 = 5;
    int max2 = 5;
    range2 = ft_range(min2, max2);
    printf("Range from %d to %d: ", min2, max2);
    print_array(range2, max2 - min2); // Should print "Array is NULL"

    // Test case 3: Negative range
    int min3 = -3;
    int max3 = 3;
    range3 = ft_range(min3, max3);
    printf("Range from %d to %d: ", min3, max3);
    print_array(range3, max3 - min3);

    // Test case 4: Larger range
    int min4 = 100;
    int max4 = 110;
    range4 = ft_range(min4, max4);
    printf("Range from %d to %d: ", min4, max4);
    print_array(range4, max4 - min4);

    // Test case 5: Single element range
    int min5 = -6;
    int max5 = 18;
    range5 = ft_range(min5, max5);
    printf("Range from %d to %d: ", min5, max5);
    print_array(range5, max5 - min5);

    // Free allocated memory
    free(range1);
    free(range3);
    free(range4);
    free(range5);

    return 0;
}