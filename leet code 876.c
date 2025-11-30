#include <stdio.h>
#include <stdlib.h>


struct node {
    int info;
    struct node* next;
};


struct node* createNode(int info) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = info;
    p->next = NULL;
    return p;
}


struct node* middleNode(struct node* start) {
    int count = 0;
    struct node* temp = start;

    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    
    int mid = count / 2;
    temp = start;
    for (int i = 0; i < mid; i++) {
        temp = temp->next;
    }
    return temp;
}


void printList(struct node* start) {
    while (start != NULL) {
        printf("%d ", start->info);
        start = start->next;
    }
    printf("\n");
}

int main() {
    int n, info;
    struct node *start = NULL, *last = NULL, *p;

    // Take input from user
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &info);
        p = createNode(info);

        if (start == NULL) {
            start = p;
            last = p;
        } else {
            last->next = p;
            last = p;
        }
    }

    
    struct node* mid = middleNode(start);

 
    printf("Middle list: ");
    printList(mid);

    return 0;
}
