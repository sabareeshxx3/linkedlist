#include<stdlib.h>
#include<stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

int main() {
    int choice;
    while (1) {
        printf("\nMENU\n");
        printf("\n1. Create\n");
        printf("\n2. Display\n");
        printf("\n3. Insert at the beginning\n");
        printf("\n4. Insert at the end\n");
        printf("\n5. Insert at specified position\n");
        printf("\n6. Delete from beginning\n");
        printf("\n7. Delete from the end\n");
        printf("\n8. Delete from specified position\n");
        printf("\n9. Exit\n");
        printf("\nEnter your choice:\t");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_begin();
                break;
            case 4:
                insert_end();
                break;
            case 5:
                insert_pos();
                break;
            case 6:
                delete_begin();
                break;
            case 7:
                delete_end();
                break;
            case 8:
                delete_pos();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
                break;
        }
    }
    return 0;
}

void create() {
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nOut of Memory Space\n");
        exit(0);
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void display() {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    } else {
        ptr = start;
        printf("\nThe List elements are:\n");
        while (ptr != NULL) {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
    }
}

void insert_begin() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nOut of Memory Space\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->data);
    temp->next = start;
    start = temp;
}

void insert_end() {
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nOut of Memory Space\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void insert_pos() {
    struct node *temp, *ptr;
    int pos, i;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("\nOut of Memory Space\n");
        return;
    }
    printf("\nEnter the position for the new node to be inserted:\t");
    scanf("%d", &pos);
    printf("\nEnter the data value of the node:\t");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (pos == 0) {
        temp->next = start;
        start = temp;
    } else {
        ptr = start;
        for (i = 0; i < pos - 1; i++) {
            ptr = ptr->next;
            if (ptr == NULL) {
                printf("\nPosition not found: [Handle with care]\n");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delete_begin() {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is Empty\n");
        return;
    } else {
        ptr = start;
        start = start->next;
        printf("\nThe deleted element is %d\n", ptr->data);
        free(ptr);
    }
}

void delete_end() {
    struct node *temp, *ptr;
    if (start == NULL) {
        printf("\nList is Empty\n");
        return;
    } else if (start->next == NULL) {
        ptr = start;
        start = NULL;
        printf("\nThe deleted element is: %d\n", ptr->data);
        free(ptr);
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        printf("\nThe deleted element is: %d\n", ptr->data);
        free(ptr);
    }
}

void delete_pos() {
    struct node *temp, *ptr;
    int pos;
    if (start == NULL) {
        printf("\nList is Empty\n");
        return;
    } else {
        printf("\nEnter the position of the node to be deleted:\t");
        scanf("%d", &pos);
        if (pos == 0) {
            ptr = start;
            start = start->next;
            printf("\nThe deleted element is: %d\n", ptr->data);
            free(ptr);
        } else {
            ptr = start;
            for (int i = 0; i < pos; i++) {
                temp = ptr;
                ptr = ptr->next;
                if (ptr == NULL) {
                    printf("\nPosition not Found\n");
                    return;
                }
            }
            temp->next = ptr->next;
            printf("\nThe deleted element is: %d\n", ptr->data);
            free(ptr);
        }
    }
}
