/*
                             Construct Binary Tree From Inorder And Preorder

Given preorder and inorder traversal of a tree, construct the binary tree.

 Note: You may assume that duplicates do not exist in the tree. 
Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3
*/
// The idea here is to iterate through preorder traversal and locate the current element in inorder traversal
// if the current element's index in inorder is idx then all the elements in inorder < idx are from left subtree of 
// current element and all elements > idx are right subtree so we can recurse.
 int get_idx(vector<int>& B,int key,int start,int end)
 {
      int idx;
      for(int i=start;i<=end;i++)
       if(key==B[i])idx=i;
       return idx;
 }
 Node* build(int& pre,int start,int end,vector<int>&A,vector<int>& B)
 {
     if(start>end)return NULL;
     if(start==end)return new Node(A[pre++]);
     int idx = get_idx(B,A[pre],start,end);
     Node* root = new Node(A[pre++]);
     root->left = build(pre,start,idx-1,A,B);
     root->right = build(pre,idx+1,end,A,B);
    return root;
 }
Node* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
     int idx=0;
    return build(idx,0,B.size()-1,A,B);
}

// we can improve the solution by using hashmap to map elements in inorder to their index..