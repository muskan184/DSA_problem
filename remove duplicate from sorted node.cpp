class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        while (current && current->next) {
            if (current->val == current->next->val) {
                current->next = current->next->next; // Skip the duplicate
            } else {
                current = current->next; // Move to the next node
            }
        }
        
        return head;
    }
};
