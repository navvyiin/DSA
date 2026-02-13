var insertionSortList = function(head) {
    if (!head || !head.next) return head;
    
    let dummy = new ListNode(0);  // start of sorted list
    let current = head;
    
    while (current) {
        let prev = dummy;
        let nextNode = current.next;  // store next node
        
        // Find correct position in sorted list
        while (prev.next && prev.next.val < current.val) {
            prev = prev.next;
        }
        
        // Insert current between prev and prev.next
        current.next = prev.next;
        prev.next = current;
        
        current = nextNode;  // move to next node in original list
    }
    
    return dummy.next;
};