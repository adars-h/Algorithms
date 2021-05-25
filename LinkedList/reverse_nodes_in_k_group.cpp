// Given a function which takes head of a linked list as a parameter and k is the group size
// you have to reverse the linked list in groups of size of k
// Ex: 1 2 2 4 8 7 6 5
// output : 4 2 2 1 5 6 7 8.
struct Node
{
	int data;
	struct Node* next;
};
struct Node* reverse(struct Node* head,int k)
{
   Node* current = head;
   Node* previous = NULL;
   Node* Next = NULL;
   int count = 0;        // keeps track of no of nodes in current group.
   while(current && count<k) // Reverses the current group.
   {
   	  Next = current->next;
   	  current->next = previous;
   	  previous = current;
   	  current = Next;
   	  count++;
   }
   if(current)   
   // if after reversing the group if there are remaining nodes to reverse then
   // recursively reverses that list.
   	 head->next = reverse(current,k);
   	// after reversing the previous becomes head of the linkedlist.
   return previous;
}