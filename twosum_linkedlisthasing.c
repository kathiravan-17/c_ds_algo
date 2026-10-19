#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key;            // Number stored
    int index;          // Original array index
    struct Node *next;  // Pointer to next node
} Node;

Node *table[SIZE] = {NULL};


// Hash function
int hash(int key)
{
    int index = key % SIZE;

    if (index < 0)
        index += SIZE;

    return index;
}


// Insert number into hash table
void insert(int key, int array_index)
{
    int index = hash(key);

    Node *n = malloc(sizeof(Node));

    if (!n)
        return;

    n->key = key;
    n->index = array_index;

    // Connect new node to existing list
    n->next = table[index];

    // Make new node the first node
    table[index] = n;
}


// Search number in hash table
int search(int key)
{
    int index = hash(key);

    Node *temp = table[index];

    while (temp != NULL) {

        if (temp->key == key)
            return temp->index;

        temp = temp->next;
    }

    return -1;
}


// Release allocated memory
void cleanup(void)
{
    for (int i = 0; i < SIZE; i++) {

        Node *temp = table[i];

        while (temp != NULL) {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }

        table[i] = NULL;
    }
}


// Two Sum
void twoSum(int nums[], int n, int target)
{
    for (int i = 0; i < n; i++) {

        int need = target - nums[i];

        // Search for required number
        int found = search(need);

        if (found != -1) {

            printf("Indices: %d, %d\n", found, i);

            return;
        }

        // Insert current number
        insert(nums[i], i);
    }

    printf("No solution found\n");
}


int main(void)
{
    int nums[] = {2, 7, 11, 15};

    int n = sizeof(nums) / sizeof(nums[0]);

    int target = 9;

    twoSum(nums, n, target);

    cleanup();

    return 0;
}
