#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int node_id;
    int data;
    struct node *left;
    struct node *right;
} node;


node *newNode(int data, int node_id) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->node_id = node_id;
    new_node->right = new_node->left = NULL;
    return new_node;
}

node *insert_node(node *root, int data, int node_id) {
    if (root == NULL)
        return newNode(data, node_id);
    else {
        node *cur;
        if (node_id < root->node_id) {
            cur = insert_node(root->left, data, node_id);
            root->left = cur;
        } else if (node_id > root->node_id) {
            cur = insert_node(root->right, data, node_id);
            root->right = cur;
        }
    }
    return root;
}


node *find_node_data(node *root, int node_id) {
    if (root == NULL)
        return NULL;
    else if (root->node_id == node_id)
        return root;
    else if (root->node_id > node_id)
        return find_node_data(root->left, node_id);
    else
        return find_node_data(root->right, node_id);
}

void print(node *np) {
    if (np) {
        print(np->left);
        printf("(%d, %d)", np->node_id, np->data);
        print(np->right);
    }
}

int main() {
    int T = 1000; //test case 1000 nodes
    int data, node_id;
    //printf("Input number of nodes:");
    //scanf("%d", &T);
    node *root = NULL;
    srand (time (NULL));
    while (T-- > 0) {
        //printf("Input data. %d:", T);
        //scanf("%d %d", &data, &node_id);
        int r = rand() % 1000;
        int r2 = rand() % 1000;
        root = insert_node(root, r, r2);
    }
    print(root);
    printf("\n");
    printf("Find data at node:", T);
    scanf("%d", &T);
    printf("node data %d", find_node_data(root, T)->data);
    return 0;
}
