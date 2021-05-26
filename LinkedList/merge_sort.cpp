// sort the linkedlist using merge sort algorithm.
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(!head || !head->next)
         return head;
        Node* mid = getmid(head); // gets  the middle node linkedlist and splits into two parts.
        Node* left = mergeSort(head); // recursively sort the left part..
        Node* right = mergeSort(mid); // recursively sort the right part..
        return merge(left,right); // merge the sorted left and sorted righted part..
    }
    // Function to merge two sorted linked lists and return the head of the list..
    Node* merge(Node* left,Node* right)
    {
        if(!left)
         return right; // if left is empty return right..
        if(!right)
         return left; // if right is empty return left..
        if(left->data < right->data)
        {
            left->next = merge(left->next,right); 
            return left;
        }
        else
        {
            right->next = merge(left,right->next);
            return right;
        }
    }
    /* 
        function that retuns the pointer to middle node of the list and at the sametime 
        splits the list into two parts..
    */
    Node* getmid(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while(slow && fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL; // splitting the list two parts...
        return slow;
    }
};
