class Solution {
    public Node flatten(Node head) {
        if (head == null) return head;

        flattenDFS(head);
        return head;
    }

    private Node flattenDFS(Node node) {
        Node curr = node;
        Node last = null;

        while (curr != null) {
            Node next = curr.next;

            if (curr.child != null) {
                Node childTail = flattenDFS(curr.child);

                curr.next = curr.child;
                curr.child.prev = curr;

                if (next != null) {
                    childTail.next = next;
                    next.prev = childTail;
                }

                curr.child = null;
                last = childTail;
            } else {
                last = curr;
            }

            curr = next;
        }

        return last;
    }
}