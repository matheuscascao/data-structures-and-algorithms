#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert_node(Node *root, int data) {
    Node *temp = (Node*) malloc(sizeof(Node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL) {
        root = temp;
    } else {
        Node *current = root;
        Node *parent = NULL;
        while(1) {
            parent = current;
            if (data < parent->data){
                current = current->left;

                if (current == NULL){
                    parent->left = temp;
                    return root;
                }
            }
            else {
                current = current->right;
      
                if (current == NULL){
                    parent->right = temp;
                    return root;
                }

            }
        } 
    }
    return root;
}

void inorder_traversal(Node *root) {
    if (root) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

Node* search(Node *root, int data){
    Node* current = root;

    while (current){
        if (data < current-> data){
            current = current->left;
        } else if(data > current->data) {
            current = current->right;
        } else {
            return current;
        }
    }
}

int main(){
    int numbers_to_be_inserted[11] = {1, 5, 2, 6, 9, 16, 91, 12, 86, 4, 78};
    Node* root = NULL;
    
    int i;
    for (i = 0; i < 11; i++){
        root = insert_node(root, numbers_to_be_inserted[i]);
        printf("Inserted: %d\n", numbers_to_be_inserted[i]);
    }

    inorder_traversal(root);

    Node *temp = search(root, 5);
    if (temp) {
        printf("Found: %d\n", temp->data);
    } else printf("Not found %d", i);

    temp = search(root, 99);
    if (temp) {
        printf("Found: %d\n", temp->data);
    } else printf("Not found %d\n", i);
    return 0;
}