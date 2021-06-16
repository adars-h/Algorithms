/*
                                 Inorder Successor of a node in Binary Tree

Given a binary tree and a node, we need to write a program to find inorder successor of this node.

Inorder Successor of a node in binary tree is the next node in Inorder traversal of the Binary Tree. 

Inorder Successor is NULL for the last node in Inorder traversal.
*/
// Idea
/*

We need to take care of 3 cases for any node to find its inorder successor as described below:
1) Right child of node is not NULL. If the right child of the node is not NULL then the inorder successor of this node
   will be the leftmost node in it’s right subtree.

2) Right Child of the node is NULL. If the right child of node is NULL. Then we keep finding the parent of the given 
node x, say p such that p->left = x. 
Below is the algorithm for this case:
Suppose the given node is x. Start traversing the tree from root node to find x recursively.
If root == x, stop recursion otherwise find x recursively for left and right subtrees.
Now after finding the node x, recur­sion will back­track to the root. Every recursive call will return the node 
itself to the calling function, we will store this in a temporary node say temp.Now, when it back­tracked to its 
par­ent which will be root now, check whether root.left = temp, if not , keep going up

3) Inorder Successor of the rightmost node in a tree is NULL.
*/
#include<bits/stdc++.h>
using namespace std;
  
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
  
// Temporary node for case 2
Node* temp = new Node;
  
// Utility function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
// function to find left most node in a tree
Node* leftMostNode(Node* node)
{
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}
  
// function to find right most node in a tree
Node* rightMostNode(Node* node)
{
    while (node != NULL && node->right != NULL)
        node = node->right;
    return node;
}
  
// recursive function to find the Inorder Scuccessor
// when the right child of node x is NULL
Node* findInorderRecursive(Node* root, Node* x )
{
    if (!root)
        return NULL;
  
    if (root==x || (temp = findInorderRecursive(root->left,x)) ||(temp = findInorderRecursive(root->right,x)))
    {
        if (temp)
        {
            if (root->left == temp)
            {
                cout << "Inorder Successor of " << x->data;
                cout << " is "<< root->data << "\n";
                return NULL;
            }
        }
  
        return root;
    }
  
    return NULL;
}
  
// function to find inorder successor of 
// a node
void inorderSuccesor(Node* root, Node* x)
{
    // Case1: If right child is not NULL
    if (x->right != NULL)
    {
        Node* inorderSucc = leftMostNode(x->right);
        cout<<"Inorder Successor of "<<x->data<<" is ";
        cout<<inorderSucc->data<<"\n";
    }
  
    // Case2: If right child is NULL
    if (x->right == NULL)
    {    
        int f = 0;
          
        Node* rightMost = rightMostNode(root);
  
        // case3: If x is the right most node
        if (rightMost == x)
            cout << "No inorder successor! Right most node.\n";
        else
            findInorderRecursive(root, x);
    }
}
// Another Approach:
/*
    We will do a reverse inorder traversal and keep the track of current visited node. Once we found the element, 
    last tracked element would be our answer.
*/
// function that prints the inorder successor
// of a target node. next will point the last 
// tracked node, which will be the answer.
void inorderSuccessor(Node* root,  Node* target_node, Node* &next)
{
    // if root is null then return
    if(!root)
        return;
  
    inorderSuccessor(root->right, target_node, next);
      
    // if target node found then enter this condition
    if(root->data == target_node->data)
    {
        // this will be true to the last node
        // in inorder traversal i.e., rightmost node.
        if(next == NULL)
            cout << "inorder successor of " 
                 << root->data << " is: null\n";
        else
            cout << "inorder successor of " 
                 << root->data << " is: " 
                 << next->data << "\n"; 
    }
    next = root; // setting next as current node and traversing the left sub tree. 

    inorderSuccessor(root->left, target_node, next);
}