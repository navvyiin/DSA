class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find cycle start
                ListNode* entry = head;

                while (entry != slow) {
                    entry = entry->next;
                    slow = slow->next;
                }

                return entry;  // cycle start
            }
        }

        return nullptr;  // no cycle
    }
};