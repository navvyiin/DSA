class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;

        Node current = head;

        // Step 1: Insert cloned nodes
        while (current != null) {
            Node clone = new Node(current.val);
            clone.next = current.next;
            current.next = clone;
            current = clone.next;
        }

        // Step 2: Assign random pointers
        current = head;
        while (current != null) {
            if (current.random != null) {
                current.next.random = current.random.next;
            }
            current = current.next.next;
        }

        // Step 3: Separate the lists
        current = head;
        Node dummy = new Node(0);
        Node copyCurrent = dummy;

        while (current != null) {
            Node clone = current.next;

            copyCurrent.next = clone;
            copyCurrent = clone;

            current.next = clone.next;
            current = current.next;
        }

        return dummy.next;
    }
}