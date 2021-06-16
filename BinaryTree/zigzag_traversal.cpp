/*
                                     ZigZag Tree Traversal 

             Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.
Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
*/
// The idea here is to use a deque data structure and push and pop the nodes in different direction depending the level
// is odd or even..
vector <int> zigZagTraversal(Node* root)
{
	deque<Node*> q;
	q.push_back(root);
	q.push_back(NULL);
	int flag=0;
	vector<int> ans;
	while(!q.empty())
	{
	    Node* top;
	    if(flag)
	     {
	         top = q.back(); // if the level is odd considering root level as 0 pop back and push front
	         q.pop_back();
	     }
	    else
	     {
	         top = q.front();
	         q.pop_front(); // if the level is even considering root level as 0 then pop front and push back
	     }
	     if(top==NULL)
	     {
	          if(q.empty())break;
	          if(flag==0)
	          q.push_front(NULL);
	          else
	           q.push_back(NULL);
	           flag = !flag;
	          continue;
	     }
	    ans.push_back(top->data);
	    if(!flag)
	    {
	        if(top->left)
	         q.push_back(top->left); // even level
	        if(top->right)
	         q.push_back(top->right);
	    }
	    else
	    {
	        if(top->right)
	         q.push_front(top->right);  // odd level
	        if(top->left)
	         q.push_front(top->left);
	    }
	}
	return ans;
}