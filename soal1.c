#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* membuatnode(int nilai) {
    node* nodebaru = (node*)malloc(sizeof(node));
    nodebaru->data = nilai;
    nodebaru->next = NULL;
    return nodebaru;
}

void pushfront(node** head, int nilai) {
    node* nodebaru = membuatnode(nilai);
    nodebaru->next = *head;
    *head = nodebaru;
}

void pushback(node** head, int nilai) {
    node* nodebaru = membuatnode(nilai);
    if (*head == NULL) {
        *head = nodebaru;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nodebaru;
}

void delete(node** head, int nilai) {
    if (*head == NULL) return;

    node* temp = *head;
    node* prev = NULL;

    if (temp != NULL && temp->data == nilai) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void find(node* head, int nilai) {
    int index = 0;
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == nilai) {
            printf("FOUND %d\n", index);
            return;
        }
        temp = temp->next;
        index++;
    }
    printf("NOT FOUND\n");
}

void print(node* head) {
    if (head == NULL) {
        printf("LIST EMPTY\n");
        return;
    }
    printf("LIST ");
    node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    node* head = NULL;

    for (int i = 0; i < q; i++) {
        int op, x;
        scanf("%d %d", &op, &x);

        if (op == 1) {
            pushfront(&head, x);
        } else if (op == 2) {
            pushback(&head, x);
        } else if (op == 3) {
            delete(&head, x);
        } else if (op == 4) {
            find(head, x);
        }
    }

    print(head);

    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
