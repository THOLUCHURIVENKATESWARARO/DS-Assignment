#include <stdio.h>

#define MAX_NODES 15

char tree[] = {'\0', 'D', 'A', 'F', 'E', 'B', 'R', 'T', 'G', 'Q', '\0', '\0', 'V', '\0', 'J', 'L'};

// Get the index of the right child of a node
int get_right_child(int index) {
    if (index >= 1 && index <= MAX_NODES / 2 && (2 * index) + 1 <= MAX_NODES) {
        return (2 * index) + 1;
    }
    return -1;
}

// Get the index of the left child of a node
int get_left_child(int index) {
    if (index >= 1 && (2 * index) <= MAX_NODES) {
        return 2 * index;
    }
    return -1;
}

// Preorder traversal (Root - Left - Right)
void preorder(int index) {
    if (index > 0 && index <= MAX_NODES && tree[index] != '\0') {
        printf(" %c ", tree[index]);
        preorder(get_left_child(index));
        preorder(get_right_child(index));
    }
}

// Postorder traversal (Left - Right - Root)
void postorder(int index) {
    if (index > 0 && index <= MAX_NODES && tree[index] != '\0') {
        postorder(get_left_child(index));
        postorder(get_right_child(index));
        printf(" %c ", tree[index]);
    }
}

// Inorder traversal (Left - Root - Right)
void inorder(int index) {
    if (index > 0 && index <= MAX_NODES && tree[index] != '\0') {
        inorder(get_left_child(index));
        printf(" %c ", tree[index]);
        inorder(get_right_child(index));
    }
}

int main() {
    printf("Preorder:\n");
    preorder(1);
    printf("\nPostorder:\n");
    postorder(1);
    printf("\nInorder:\n");
    inorder(1);
    printf("\n");
    return 0;
}
