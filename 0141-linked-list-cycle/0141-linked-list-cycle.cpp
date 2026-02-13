class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) 
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;          // move 1 step
            fast = fast->next->next;    // move 2 steps

            if (slow == fast) {
                return true;            // cycle detected
            }
        }

        return false;   // reached NULL → no cycle
    }
};