#include <stdio.h>

typedef struct {
    int first;
    int second;
} IndexPair;

// ponytail: O(n^2) brute force; use a hash map for O(n) if inputs get large
IndexPair find_basic_two_sum(int *a, int size, int target)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (a[i] + a[j] == target)
            {
                // Compound literal (C99): builds an unnamed IndexPair
                // in place and returns it, with no temp variable needed
                return (IndexPair){i, j};
            }
        }
    }
    // Compound literal with {-1, -1} means no pair was found
    return (IndexPair){-1, -1};
}

int main()
{
    int arr[] = {1, 2, 3, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    IndexPair k = find_basic_two_sum(arr, size, 10);
    printf("%d %d \n", k.first, k.second);
    return 0;
}
