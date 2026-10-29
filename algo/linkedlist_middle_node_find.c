#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int value) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;
    return n;
}

// Build a list from an array
Node *buildList(int arr[], int size) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < size; i++) {
        Node *n = createNode(arr[i]);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    return head;
}

void printList(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node *middle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;          // 1 step
        fast = fast->next->next;    // 2 steps
    }
    return slow;   // for even length, this is the 2nd middle
}

void freeList(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int odd[]  = {1, 2, 3, 4, 5};
    int even[] = {1, 2, 3, 4, 5, 6};

    Node *a = buildList(odd, 5);
    Node *b = buildList(even, 6);

    printf("List: "); printList(a);
    printf("Middle: %d\n\n", middle(a)->data);

    printf("List: "); printList(b);
    printf("Middle: %d\n", middle(b)->data);

    freeList(a);
    freeList(b);
    return 0;
}
