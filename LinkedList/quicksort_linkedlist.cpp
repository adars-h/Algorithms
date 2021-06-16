/*
 Given a head of a singly linkedlist sort the linkedilst using quicksort algorithm and return the new head of the 
 sorted list
*/
/*
    The important things about implementation are, it changes pointers rather swapping data

    In partition(), we consider last element as pivot. We traverse through the current list and if a node has value
    greater than pivot, we move it after tail. If the node has smaller value, we keep it at its current position. 

    In QuickSortRecur(), we first call partition() which places pivot at correct position and returns pivot. 
    After pivot is placed at correct position, we find tail node of left side (list before pivot) and recur for left 
    list. Finally, we recur for right list.

*/
 Node* getTail( Node* cur)
 {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
 }

Node* partition( Node* head,Node* end,Node** newHead,Node** newEnd)
{
     Node* pivot = end;
     Node *prev = NULL, *cur = head, *tail = pivot;
    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}

// here the sorting happens exclusive of the end node
Node* quickSortRecur( Node* head,Node* end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    Node *newHead = NULL, *newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be
    // updated by the partition function
     Node* pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
         Node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to
        // pivot
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
 
    return newHead;
}

void quickSort(struct Node** headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}