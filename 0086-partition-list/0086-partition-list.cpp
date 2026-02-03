/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy heads for two lists
        ListNode lessDummy(0);
        ListNode greaterDummy(0);

        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Important: terminate the greater list
        greater->next = nullptr;

        // Join the two lists
        less->next = greaterDummy.next;

        return lessDummy.next;
    }
};