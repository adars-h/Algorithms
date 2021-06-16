/*
                                        Left View of Binary Tree

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is 
visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /  \     /   \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3
*/

// The idea here is to use a preorder traversal and for every new level we should insert only the first visited node.

void left(Node* root,int level,vector<int>& ans)
{
    if(root==NULL)return;
    if(level>=ans.size())
    {
    // ans stores the currently visited nodes which are atmost left of the binary tree at each level.
       ans.push_back(root->data);
    }
    left(root->left,level+1,ans);
    left(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   left(root,0,ans);
   return ans;
}
// Time Complexity: O(N) where N is the no of nodes.
// Space Complexity: O(N) as we are using vector to store the nodes.