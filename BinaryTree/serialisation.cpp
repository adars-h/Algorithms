/*
Serialization is to store tree in a file so that it can be later restored. 
The structure of tree must be maintained. Deserialization is reading tree back from file.

If the given Binary Tree is Binary Search Tree, we can store it by either storing preorder or postorder traversal.
In case of Binary Search Trees, only preorder or postorder traversal is sufficient to store structure information.

For a complete Binary Tree, level order traversal is sufficient to store the tree. We know that the first node is
root, next two nodes are nodes of next level, next four nodes are nodes of 2nd level and so on. 

How to store a general Binary Tree? 
A simple solution is to store both Inorder and Preorder traversals. This solution requires space twice the size of Binary Tree. 
We can save space by storing Preorder traversal and a marker for NULL pointers. 

Let the marker for NULL pointers be '-1'
Input:
     12
    /  
  13   
Output: 12 13 -1 -1 -1

Input:
      20
    /   \
   8     22 
Output: 20 8 -1 -1 22 -1 -1 

Input:
         20
       /    
      8     
     / \
    4  12 
      /  \
     10  14
Output: 20 8 4 -1 -1 12 10 -1 -1 14 -1 -1 -1 

Input:
          20
         /    
        8     
      /
    10
    /
   5
Output: 20 8 10 5 -1 -1 -1 -1 -1 

Input:
          20
            \
             8
              \   
               10
                 \
                  5   
Output: 20 -1 8 -1 10 -1 5 -1 -1
*/
string serialize(Node* root)
{
     string s = "";
     if(root==NULL)
      return s+'-1';
    // serialize the left sub tree 
    string left = serialize(root->left);
    // serialize the right sub tree
    string right = serialize(root->right);
    // serialize the current tree
    s+= (char)root->data + left + right;
  
  return s;
}