/*
                                 Duplicate subtree in Binary Tree

   Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
 
Example 2 :
Input : 
               1
             /   \ 
           2       3

Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.
*/
// solution
/*
   A simple solution is that, we pick every node of tree and try to find is any sub-tree of given tree is present 
  in tree which is identical with that sub-tree. Here we can use below post to find if a subtree is present 
  anywhere else in tree. 

  An Efficient solution based on tree serialization and hashing. The idea is to serialize subtrees as strings and 
  store the strings in hash table. Once we find a serialized tree (which is not a leaf) already existing in 
  hash-table, we return true. 
*/
map<string,int> mp;
string helper(Node* root)
{
     string s = ""; // return the empty string if subtree is found twice in current tree.
      // If current node is NULL, return '#'
     if(root==NULL)
      return s+'#';
    // If left subtree has a duplicate subtree.
    string left = helper(root->left);
    if(left=="")
     return s;
    // Do same for right subtree
    string right = helper(root->right);
    if(right=="")
     return s;
    // Serialize current subtree
    s+= (char)root->data + left + right;
    // If current subtree already exists in hash
    // table. [Note that size of a serialized tree
    // with single node is 3 as it has two marker
    // nodes.
  if(s.size()>3 && mp[s])
   return "";
  mp[s]++;
  return s;
}
bool dupSub(Node *root)
{
    mp.clear();
    return helper(root)=="";
     
}