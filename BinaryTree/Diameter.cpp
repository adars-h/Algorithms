/*
                                       Diameter of Binary Tree 

                              Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree.

Example 1:
Input:
       1
     /  \
    2    3
Output: 3

Example 2:
Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
*/

/*
 The Diameter is max of three values, if we consider root as our root of Tree then 
  Diameter = max ( 
      height_left_sub_tree+height_right_sub_tree+1,
      diameter_of_left_subtree,
      diameter_of_right_subtree
                 )
*/

class Solution
{
    public:
    //Function to return the diameter of a Binary Tree.
    int height(Node* root)
    {
        if(!root)return 0;
        if(!root->left && !root->right)
         return 1;
        return 1+max(height(root->left),height(root->right));
    }
    int diameter(Node* root)
    {
       if(root==NULL)return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(1+left+right,max(diameter(root->left),diameter(root->right)));
    }

};
// Time Complexity: O(N*N) where N is the number of Nodes.
// we can reduce time complexity by caculating height in the same recursion call as the diameter function.
int diameter(Node* root,int& height)
{
    if(root==NULL)
     return 0;
    int left_subtree_height = 0,right_subtree_height = 0;
    int left_subtree_diameter = diameter(root->left,left_subtree_height);
    int right_subtree_diameter = diameter(root->right,right_subtree_height);
    height = 1 + max(left_subtree_height,right_subtree_height);
    return max (
        {
            1+left_subtree_height+right_subtree_height,
            left_subtree_diameter,
            right_subtree_diameter
        }      );
}
// Time Complexity: O(N) where N is the number of nodes.