/*
                                    92. Reverse Linked List II

 Given the head of a singly linked list and two integers left and right where left <= right, 
 reverse the nodes of the list from position left to position right, and return the reversed list. 

Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]                     

*/

// The main idea is to use recursion and in the recursive call  traverse till the left position and iteratively
// reverse from left to right and return the head of the reversed list.. and in the calls upto position left 
// update the next links accordingly
// solution:
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
      if(left!=1)
      {
          head->next = reverseBetween(head->next,left-1,right-1);// traverse upto left position
          return head;
      }
      else
      {  
          // if the current position is left reverse the linked list upto right..
          int count = 0;
          ListNode* prev = NULL, *curr = head,*next = NULL;
          while(count<right)
          {
              count++;
              next = curr->next;
              curr->next = prev;
              prev = curr;
              curr = next;
          }
          head->next = curr;
          return prev;
      }
    }
};