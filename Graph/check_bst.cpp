#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left, *right;
};

bool isBST(Node *root, Node *l = NULL, Node *r = NULL)
{
    if (root == NULL)
        return true;
    if (l != NULL and root->data <= l->data)
        return false;
    if (r != NULL and root->data >= r->data)
        return false;

    return isBST(root->left, l, root) && isBST(root->right, root, r);
}

struct Node *newNode(int data)
{
    struct Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
main()
{
    struct Node *root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(4);
    if (isBST(root, NULL, NULL))
        cout << "Is BST";
    else
        cout << "Not a BST";
}
