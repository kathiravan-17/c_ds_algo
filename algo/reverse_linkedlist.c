#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createnode(int value)
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=value;
    p->next=NULL;
    
    return p;
}

// Print the list
void printList(Node *head) {
    while(head)
    {
        printf("this is india %d\n",head->data);
        head=head->next;
    }
}
Node* reverse(Node * head)
{
    Node * prev=NULL;
    while(head)
    {
       Node * next=head->next;
       head->next=prev;
       prev=head;
       head=next;
    }
    return prev;
}
// Free memory
void freeList(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    
    Node *head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    printf("Original: ");
    printList(head);

   head = reverse(head);

    printf("Reversed: ");
    printList(head);

    freeList(head);
    return 0;
}
