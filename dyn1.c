// Dynamic memory allocation

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *ptr = (int *)malloc(n * sizeof(int));

    // input
    for (int i = 0; i < n; i++)
    {
        printf("Enter element at position %d: ", i);
        scanf("%d", ptr + i);
    }

    // display
    printf("Elements are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", *(ptr + i));
    }

    free(ptr);
}