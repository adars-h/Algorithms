/*
                                   Top View of Binary Tree

    Given below is a binary tree. The task is to print the top view of binary tree. 
    Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. 
    For the given below tree

           1
        /     \
       2       3
      /  \    /  \
     4    5  6    7

    Top view will be: 4 2 1 3 7
    Note: Return nodes from leftmost node to rightmost node.

    Example 1:

    Input:
        1
      /    \
     2      3
    Output: 2 1 3
    Example 2:

    Input:
           10
        /      \
      20        30
     /   \    /    \
    40   60  90    100
    Output: 40 20 10 30 100
        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
*/
/*
 we need to put nodes of same horizontal distance together. We do a level order traversal so that the topmost node 
 at a horizontal node is visited before any other node of same horizontal distance below it. Hashing is used to 
 check if a node at given horizontal distance is seen or not. 
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.  
  vector<int> topView(Node *root)
  {
      vector<int> ans;
      if(root==NULL)return ans;
      map<int,int>mp;
      queue<pair<Node*,int>> q;
      q.push({root,0});
      int distance = 0;
      while(!q.empty())
      {
          pair<Node*,int> top = q.front();
          q.pop();
          if(!mp.count(top.second))
          mp[top.second] = top.first->data;
          if(top.first->left)
           q.push({top.first->left,top.second-1});
          if(top.first->right)
           q.push({top.first->right,top.second+1});
      }
      for(auto it:mp)
       ans.push_back(it.second);
 }

};
// Time Complexity: O(NlogN) N is no of nodes
// Space Complexity: O(N)

// We can optimize the time complexity further by using stack to keep track of left most node and vector
// to keep track of right most nodes..
void topView()
    {
        // queue for holding nodes and their horizontal
        // distance from the root node
        queue<pair<Node*, int> > q;
        // pushing root node with distance 0
        q.push(make_pair(root, 0));
 
        // hd is currect node's horizontal distance from root node 
        // l is currect left min horizontal distance (or max in magnitude) so far from the root node 
        // r is currect right max horizontal distance so far from the root node
 
        int hd = 0, l = 0, r = 0;
 
        // stack is for holding left node's data because
        // they will appear in reverse order that is why
        // using stack
        stack<int> left;
 
        // vector is for holding right node's data
        vector<int> right;
 
        Node* node;
 
        while (q.size()) {
 
            node = q.front().first;
            hd = q.front().second;
 
            if (hd < l) {
                left.push(node->data);
                l = hd;
            }
            else if (hd > r) {
                right.push_back(node->data);
                r = hd;
            }
 
            if (node->left) {
                q.push(make_pair(node->left, hd - 1));
            }
            if (node->right) {
                q.push(make_pair(node->right, hd + 1));
            }
 
            q.pop();
        }
        // printing the left node's data in reverse order
        while (left.size()) {
            cout << left.top() << " ";
            left.pop();
        }
 
        // then printing the root node's data
        cout << root->data << " ";
 
        // finally printing the right node's data
        for (auto x : right) {
            cout << x << " ";
        }
    }
// Time Complexity: O(N) N is no of nodes
// Space Complexity: O(N)