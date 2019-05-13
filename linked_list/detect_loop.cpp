/* Write a function detectAndRemoveLoop() that checks whether a given Linked List contains loop
 * and if loop is present then removes the loop and returns true. And if the list doesn’t contain
 * loop then returns false.
 */

// Function to detect and remove loop 
// in a linked list that may contain loop 
void detectAndRemoveLoop(Node *head) 
{ 
    // If list is empty or has only one node 
    // without loop 
    if (head == NULL || head->next == NULL) 
        return; 
  
    Node *slow = head, *fast = head; 
  
    // Move slow and fast 1 and 2 steps 
    // ahead respectively. 
    slow = slow->next; 
    fast = fast->next->next; 
  
    // Search for loop using slow and 
    // fast pointers 
    while (fast && fast->next) 
    { 
        if (slow == fast) 
            break; 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
  
    /* If loop exists */
    if (slow == fast) 
    { 
        slow = head; 
        while (slow->next != fast->next) 
        { 
            slow = slow->next; 
            fast = fast->next; 
        } 
  
        /* since fast->next is the looping point */
        fast->next = NULL; /* remove loop */
    } 
}



/* Proof of the above method */

n --> length of the cycle
m --> distance of the first node in the cycle to the head
k --> distance of the first node in the cycle to the point where slow and fast pointers meet.

Distance traveled by fast pointer = 2 * (Distance traveled
                                         by slow pointer)

(m + n*x + k) = 2*(m + n*y + k)

Note that before meeting the point shown above, fast
was moving at twice speed.

x -->  Number of complete cyclic rounds made by
       fast pointer before they meet first time

y -->  Number of complete cyclic rounds made by
       slow pointer before they meet first time

From above equation, we can conclude below

    m + k = (x-2y)*n

Which means m+k is a multiple of n. 

So if we start moving both pointers again at same speed such that one pointer (say slow) begins from head node of linked list and other pointer (say fast) begins from meeting point. When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made also moved m steps as they are now moving same pace. Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. Can they meet before also? No because slow pointer enters the cycle first time after m steps.
