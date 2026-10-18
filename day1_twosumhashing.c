
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int key;
    int index;
    bool used;
} Entry;

typedef struct {
    int i;
    int j;
} Result;

Result two_sum(int *a, int n, int target)
{
    size_t cap = (size_t)n * 2 + 1;
    Entry *table = calloc(cap, sizeof(Entry));

    if (!table)
        return (Result){-1, -1};

    for (int i = 0; i < n; i++) {

        // Find missing number
        int64_t need = (int64_t)target - a[i];

        if (need >= INT32_MIN && need <= INT32_MAX) {
            // Hash the missing number
            size_t pos = (uint32_t)need % cap;

            // Search for matching number
            while (table[pos].used) {
                if (table[pos].key == (int)need) {
                    Result result = {table[pos].index, i};
                    free(table);
                    return result;
                }

                // Collision: move to next slot
                pos = (pos + 1) % cap;
            }
        }

        // Hash current number
        size_t pos = (uint32_t)a[i] % cap;

        // Find free slot
        while (table[pos].used) {
            if (table[pos].key == a[i])
                break;

            pos = (pos + 1) % cap;
        }

        // Insert if not already present
        if (!table[pos].used)
            table[pos] = (Entry){a[i], i, true};
    }

    free(table);
    return (Result){-1, -1};
}

int main(void)
{
    int a[] = {2, 7, 11, 15};
    int n = sizeof(a) / sizeof(a[0]);

    Result r = two_sum(a, n, 9);

    printf("Indices: %d %d\n", r.i, r.j);
    return 0;
}
