
#include <stdio.h>
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result=0;
        ListNode* current=head;
        while (current != nullptr){
            result=result * 2 + current->val;
            current=current->next;
        }
        return result;
    }
};
