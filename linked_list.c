#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

void printLinkedList(struct Node *head){
    struct Node *temp = head;

    while (temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}

struct Node *create_new_node(int value){
    struct Node *node = malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    
    return node;
}

struct Node *insert_at_head(struct Node **head, struct Node *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;

    return node_to_insert;
}

struct Node *find_node(struct Node *head, int value){
    struct Node *temp = head;

    while (temp != NULL) {
        if(temp->value == value) {
            return temp;
        }
        temp = temp->next;
    }
}

struct Node *insert_node_after_specified_value(struct Node *head, int searched_value, int value_to_insert){
    struct Node *temp;
    struct Node *new_node;

    temp = find_node(head, searched_value);
    new_node = create_new_node(value_to_insert);
    new_node->next = temp->next;
    temp->next = new_node;
    return temp;
}

struct Node *remove_node_by_specified_value(struct Node *head, int value_to_be_removed){
    struct Node *temp = head;
    struct Node *new_node;

    while (temp != NULL) {
        if(temp->next->value == value_to_be_removed) {
            // printf("Address: %p; Value: %d\n", temp, temp->value);
            // printf("Address: %p; Value: %d\n", temp->next, temp->next->value);

            temp->next = temp->next->next;
            return temp;
        }
        temp = temp->next;
    }
    
}


int main(){

    struct Node *head = NULL;
    struct Node *temp, *found;

    for (int i = 0; i < 10; i++) {
        temp = create_new_node(i);
        insert_at_head(&head, temp);
    }

    found = find_node(head, 3);
    printf("Address: %p; Value: %d\n", found, found->value);

    insert_node_after_specified_value(head, 3, 13);

    printLinkedList(head);
    remove_node_by_specified_value(head, 0);
    printLinkedList(head);
    return 0;
}