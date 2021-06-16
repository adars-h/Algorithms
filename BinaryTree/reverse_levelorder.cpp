/*
                                       Reverse Level Order Traversal

    Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the 
    last level.

    Example 1:

    Input :
            1
        /   \
        3     2

    Output: 3 2 1
    Explanation:
    Traversing level 1 : 3 2
    Traversing level 0 : 1
    Example 2:

    Input :
        10
        /  \
        20   30
        / \ 
    40  60

    Output: 40 60 20 30 10
    Explanation:
    Traversing level 2 : 40 60
    Traversing level 1 : 20 30
    Traversing level 0 : 10
*/
/*
  The main idea is to use a queue and push the root node initially in to the queue and for each next iteraton 
  till the queue is empty if the front node has right child then push the right child to queue and if it has left
  child then push it to the queue
*/
// we can also use stack instead of using vector and reversing it...
vector<int> reverseLevelOrder(Node *root)
{
     vector<int> ans;
     queue<Node*> q;
     q.push(root);
     while(!q.empty())
     {
         Node* top = q.front();
         q.pop();
         ans.push_back(top->data);
         if(top->right)
          q.push(top->right);
          if(top->left)
          q.push(top->left);
     }
     reverse(ans.begin(),ans.end()); // all nodes are stored in reverse orddr so we need to reverse the vector..
     return ans;
}