#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int node_id;
    int data;
    char *name;
    struct node *left;
    struct node *right;
} node;


node *newNode(int data, char *name, int node_id) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->name = name;
    new_node->node_id = node_id;
    new_node->right = new_node->left = NULL;
    return new_node;
}

node *insert_node(node *root, int data, int node_id, char *name) {
    if (root == NULL)
        return newNode(data, name, node_id);
    else {
        node *cur;
        if (node_id < root->node_id) {
            cur = insert_node(root->left, data, node_id, name);
            root->left = cur;
        } else if (node_id > root->node_id) {
            cur = insert_node(root->right, data, node_id, name);
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
        printf("(%d, %d, %s)", np->node_id, np->data, np->name);
        print(np->right);
    }
}

int main() {
    int T = 10; //test case 10 nodes
    int data, node_id, r2, r;
    //printf("Input number of nodes:");
    //scanf("%d", &T);
    node *root = NULL;
    srand(time(NULL));
    while (T-- > 0) {
        //printf("Input data. %d:", T);
        //scanf("%d %d", &data, &node_id);
        r = rand() % 100; //node id
        r2 = T* (rand() % 100); // data
        root = insert_node(root, r2, r, "foobar");
    }
    print(root);
   // printf("\n");
   // printf("Find data at node:");
   // scanf("%d", &T);
    T = r;
    printf("node data %d %s", find_node_data(root, T)->data, find_node_data(root, T)->name);
    //printf("node data %d %s", find_node_data(NULL, T)->data, find_node_data(NULL, T)->name);
    return 0;
}
