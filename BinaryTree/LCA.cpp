/*
                               Lowest Common Ancestor in a Binary Tree

Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is to find the lowest common
ancestor of the given two nodes. We may assume that either both n1 and n2 are present in the tree or none of them
is present. 

Example 1:

Input:
n1 = 2 , n2 =  3
     1
   /  \
  2    3
Output: 1
Explanation:
LCA of 2 and 3 is 1.
Example 2:

Input:
n1 = 3 , n2 = 4
         5
        /
       2
     /  \
    3    4
Output: 2
Explanation: 
LCA of 3 and 4 is 2.
*/
// The idea is if the left subtree has n1 and n2 then lowest common ancestor lies in left subtree
// if right subtree contains both n1 and n2 lowest commong ancestor lies in right subtree
// if one tree contains one element and another contains another element curr is lca..
class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
   int helper(Node* root,int n1,int n2,Node*& ans)
    {
          if(root==NULL)
           return false;
           int curr = false; 
          if(root->data==n1 || root->data==n2)
               curr = true;
         // check if left subtree has n1 and n2
         int left = helper(root->left,n1,n2,ans);
         // check if right subtree has n1 and n2
         int right = helper(root->right,n1,n2,ans);

         if((left+right+curr)>=2) 
           ans = root;
           
         return left+right+curr>0;
     
    }
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       Node* ans = NULL;
       if(root==NULL)return root;
       if(root->data== n1 || root->data==n2)
       return root;
       helper(root,n1,n2,ans);
       if(ans==NULL)return root;
       return ans;
    }
};
// Another approach
 Node* findLCAUtil(Node* root, int n1, int n2, bool &v1, bool &v2)
{
    // Base case
    if (root == NULL) return NULL;

    // If either n1 or n2 matches with root's key, report the presence
    // by setting v1 or v2 as true and return root (Note that if a key
    // is ancestor of other, then the ancestor key becomes LCA)
    if (root->key == n1)
    {
        v1 = true;
        return root;
    }
    if (root->key == n2)
    {
        v2 = true;
        return root;
    }

    // Look for keys in left and right subtrees
    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);
    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
}

// Returns true if key k is present in tree rooted with root
bool find(Node *root, int k)
{
    // Base Case
    if (root == NULL)
        return false;

    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->key == k || find(root->left, k) ||  find(root->right, k))
        return true;

    // Else return false
    return false;
}

// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;
Node *findLCA(Node *root, int n1, int n2)
{
    // Initialize n1 and n2 as not visited
    bool v1 = false, v2 = false;

    // Find lca of n1 and n2 using the technique discussed above
    Node *lca = findLCAUtil(root, n1, n2, v1, v2);

    // Return LCA only if both n1 and n2 are present in tree
    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
        return lca;

    // Else return NULL
    return NULL;
}