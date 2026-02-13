var sortList = function(head) {
    if (!head || !head.next) return head;
    
    // Step 1: Find middle
    let slow = head;
    let fast = head;
    let prev = null;
    
    while (fast && fast.next) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }
    
    // Cut the list into two halves
    prev.next = null;
    
    // Step 2: Recursively sort both halves
    let left = sortList(head);
    let right = sortList(slow);
    
    // Step 3: Merge sorted halves
    return merge(left, right);
};

function merge(l1, l2) {
    let dummy = new ListNode(0);
    let current = dummy;
    
    while (l1 && l2) {
        if (l1.val < l2.val) {
            current.next = l1;
            l1 = l1.next;
        } else {
            current.next = l2;
            l2 = l2.next;
        }
        current = current.next;
    }
    
    // Attach remaining nodes
    current.next = l1 ? l1 : l2;
    
    return dummy.next;
}