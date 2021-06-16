/*
             Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
//solution:
/*
  The idea here is to think what if we have already right part of the linked list reversed and we are at current 
  node For ex:  we have linked list 1->2->4->3->5->6->NULL and we have reversed part of this linked list upto 
  element 3 like this head->1->2->4-> 3<-5<-6<-ans  and we are at currently node 4 in the recursive call,then we 
  need to set 3's next pointer value to current node which is 4 and current's next pointer to NULL,and return the 
  head then our list will become like 1->2-> 4<-3<-5<-6<-head 
                                             |
                                            NULL
*/
ListNode* reverse(ListNode* head)
{
    if(!head || !head->next)
     return head;
    ListNode* ans = reverse(head->next); // ans is the head of our reversed linked list which points to last node.
    head->next->next = head;
    head->next = NULL;
    return ans;
}