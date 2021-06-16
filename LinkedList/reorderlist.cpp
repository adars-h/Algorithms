/*
    Given a singly linked list 
    L: L0 → L1 → … → Ln-1 → Ln,
    reorder it to:
    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
    You must do this in-place without altering the nodes’ values.
    For example,
    Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
/*
    1) Break the list from middle into 2 lists.
    2) Reverse the latter half of the list.
    3) Now merge the lists so that the nodes alternate.
*/
ListNode* reverse(ListNode* head)
 {
     if(!head || !head->next)
      return head;
     ListNode* ans = reverse(head->next);
     head->next->next = head;
     head->next = NULL;
     return ans;
 }
ListNode* reorderList(ListNode* A) 
{
    // divide two equal parts...
    if(!A || !A->next)return A;
    ListNode* slow = A,*fast = A,*prev = NULL;
    while(slow && fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* head2;
    if(!fast)
    {
       head2 = prev->next;
       prev->next = NULL;
       head2 = reverse(head2);
    }
   else
   {
       head2 = slow->next;
       slow->next = NULL;
       head2 = reverse(head2);
   }
   
    ListNode* curr1 = A;
    // merge alternate nodes...
    while(curr1 && head2)
    {
      ListNode* next = curr1->next;
      curr1->next = head2;
      ListNode* next2 = head2->next;
      head2->next = next;
      head2 = next2;
      curr1 = next;
    }
    return A;
    
}
