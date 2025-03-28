class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = NULL;
        while(head){
            ListNode* temp = head;
            head = head->next;
            temp->next=NULL;
            if(newHead == NULL) newHead = temp;
            else if(newHead->val >= temp->val){
                temp->next = newHead;
                newHead = temp;
            }
            else{
                ListNode* root = newHead;
                {
                while(root->next){
                    if(temp->val > root->val and temp->val <= root->next->val){
                        temp->next = root->next;
                        root->next = temp;
                        break;
                    }
                    root = root->next;
                }  
                    if(root->next==NULL) root->next = temp;
                    
                }
            }
        }
        return newHead;
    }
};
