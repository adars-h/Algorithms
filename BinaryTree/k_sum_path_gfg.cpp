/*                                   
                                      Print all k-sum paths in a binary tree

        A binary tree and a number k are given. Print every path in the tree with sum of the nodes in the path as k.
    A path can start from any node and end at any node and must be downward only, i.e. they need not be root node and 
    leaf node; and negative numbers can also be there in the tree.
    Examples:

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    
                       
Output :
3 2 
3 1 1 
1 3 1 
4 1 
1 -1 4 1 
-1 4 2 
5 
1 -1 5 
*/

// solution:
/*
    The basic idea to solve the problem is to do a preorder traversal of the given tree. We also need a container 
    (vector) to keep track of the path that led to that node. At each node we check if there are any path that sums to k,
    if any we print the path and proceed recursively to print each path.
*/
void print_vector(vector<int>& path,int idx)
{
     for(int i=idx;i<path.size();i++)
      cout << path[i] << " ";
      cout << endl;
}
void printk_path_util(Node* root,int k,vector<int>& path)
{
     if(!root)
      return;
      // add current node to the path
      path.push_back(root->data);
  
    // check if there's any k sum path
    // in the left sub-tree.
    printk_path_util(root->left, path, k);
  
    // check if there's any k sum path
    // in the right sub-tree.
    printk_path_util(root->right, path, k);
  
    // check if there's any k sum path that
    // terminates at this node
    // Traverse the entire path as
    // there can be negative elements too
    int sum = 0;
    for (int j=path.size()-1; j>=0; j--)
    {
        sum += path[j];
  
        // If path sum is k, print the path
        if (sum == k)
            print_vector(path, j);
    }
  
    // Remove the current element from the path
    path.pop_back();
}
void printkPath(Node* root,int k)
{
     vector<int> path;
     printk_path_util(root,k,path);
}