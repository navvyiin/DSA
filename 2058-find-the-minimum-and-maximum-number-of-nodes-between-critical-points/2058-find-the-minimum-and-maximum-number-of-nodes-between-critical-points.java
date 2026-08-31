class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int[] result = {-1, -1};

        if (head == null || head.next == null || head.next.next == null) {
            return result;
        }

        int index = 1;
        int first = -1;
        int prevCritical = -1;
        int minDistance = Integer.MAX_VALUE;

        ListNode prev = head;
        ListNode curr = head.next;

        while (curr.next != null) {
            ListNode next = curr.next;

            boolean isMax = curr.val > prev.val && curr.val > next.val;
            boolean isMin = curr.val < prev.val && curr.val < next.val;

            if (isMax || isMin) {
                if (first == -1) {
                    first = index;
                } else {
                    minDistance = Math.min(minDistance, index - prevCritical);
                }

                prevCritical = index;
            }

            prev = curr;
            curr = next;
            index++;
        }

        if (first == -1 || first == prevCritical) {
            return result;
        }

        int maxDistance = prevCritical - first;

        result[0] = minDistance;
        result[1] = maxDistance;

        return result;
    }
}