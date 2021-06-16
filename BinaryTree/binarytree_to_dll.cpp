/*
                                     Binary Tree to DLL

    Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
   The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL
   The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal 
   (leftmost node in BT) must be the head node of the DLL.
Example 1:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3 
Explanation: DLL would be 3<=>1<=>2
Example 2:

Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:  DLL would be 
40<=>20<=>60<=>10<=>30.
*/
// The idea here is to convert left sub tree to dll ,right sub tree to dll
// and link last node of left sub tree's dll to root and first node of right sub tree's dll to root and return
// head of the dll.
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        if(root==NULL)
         return NULL;
        if(!root->left && !root->right) // if the root is leaf node.
         return root;
         // convert left sub tree to dll
        Node* lchild = bToDLL(root->left); 
        // convert right sub tree to dll
        Node* rchild = bToDLL(root->right); 
        // find last node of left subtree's dll
        Node* curr = lchild; 
        while(curr && curr->right)
         curr = curr->right;
        // if it is not NULL then link it with the root.
        if(curr) 
        curr->right = root;

        root->left = curr;
        // link right subtree's dll to root 
        root->right = rchild;
        if(rchild)
         rchild->left = root;
        curr = root;
        // return the head of the dll linkedlist since head lies to the left we should traverse to the left.
        while(curr->left)
         curr = curr->left;
        return curr;
        
    }
};
// We can solve it using another approach by doing inorder traversal and keep tracking most previously visited 
// node in a variable and linking the current node with pre..
void bToDll(Node* root, Node** head)
{
      if(!root)
       return root;
    static most_previously_visited = NULL;
   // Traverse left subtree first.
    bToDll(root->left,head);

    if(most_previously_visited == NULL)
      *head = root;
    else
    {
        root->left = most_previously_visited;
        most_previously_visited->right = root;
    }
    most_previously_visited = root;
    // Traverse right subtree 
    bToDll(root->right,head);
    
}
// we can use double pointers instead of static variables.