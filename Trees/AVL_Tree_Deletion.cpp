
#include<bits/stdc++.h>
using name space as std;

struct Node
{  
 int data, height;
 Node *left,*right;
  Node(int x)
{
  data = x;
  height = 1;
  left = right = NULL;
}
}

int height(Node *root){
    if(!root)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight>rightHeight?leftHeight:rightHeight)+1;
}
int bf(Node *root){
    if(!root)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return rightHeight-leftHeight;
}
Node *leftRotation(Node *x){
    Node *y = x->right;
    Node *T = y->left;
    
    x->right = T;
    y->left = x;
    return y;
}
Node *rightRotation(Node *x){
    Node *y = x->left;
    Node *T = y->right;
    
    x->left = T;
    y->right = x;
    return y;
}
int findMax(Node *head){
    if(!head)
        return -1;
    while(head->left){
        head = head->left;
    }
    return head->data;
}