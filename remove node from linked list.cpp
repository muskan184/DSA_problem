class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;

    while (current) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}
    ListNode* removeNodes(ListNode* head) {
           if (!head || !head->next) return head;
    head = reverseList(head);
    ListNode* current = head;
    int maxVal = current->val;
    while (current && current->next) {
        if (current->next->val < maxVal) {
            current->next = current->next->next; 
        } else {
            current = current->next; 
            maxVal = current->val; 
        }
    }
    return reverseList(head);
}
        
    
};
