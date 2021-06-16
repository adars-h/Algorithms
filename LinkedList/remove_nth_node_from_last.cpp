/*
    Given a linked list, remove the nth node from the end of list and return its head.
    For example,
    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes 1->2->3->5
    If n is greater than the size of the list, remove the first node of the list.
*/
/*
    Obviously, since we do not have back pointers, reaching the end node and then making our way back is not an option.
    There are 2 approaches :
    1) Find out the length of the list in one go. Then you know the number of node to be removed. Traverse to the node and remove it.
    2) Make the first pointer go n nodes. Then move the second and first pointer simultaneously. This way, the first 
    pointer is always ahead of the second pointer by n nodes. So when first pointer reaches the end, you are on the 
    node to be removed.
*/
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) 
{
    ListNode* slow = A,*fast = A;
    for(int i=0;i<B && fast;i++)
     fast = fast->next;
    if(!fast)
     {
         A = A->next;
         return A;
     }
     ListNode* prev = NULL;
     while(fast)
     {
          prev = slow;
          slow = slow->next;
          fast = fast->next;
     }
     prev->next = slow->next;
     return A;
}