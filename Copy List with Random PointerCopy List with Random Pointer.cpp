/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void insertCopyBetween(Node* head){
        Node* temp=head;
        while(temp != NULL){
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextElement;
            temp->next=copy;

            temp=nextElement;
        }
    }
    void connect(Node* head){
          Node* temp=head;
        while(temp != NULL){
         Node *copyNode = temp->next;

         if(temp->random){
            copyNode->random=temp->random->next;
         }else{
            copyNode->random = nullptr;
         }
         temp= temp->next->next;
        }
    }
    Node* getdeepcopy(Node* head){
        Node* temp =head;
        Node* dummyNode= new Node(-1);
        Node* res= dummyNode;

        while(temp != NULL){
            res->next=temp->next;
            res=res->next;
            temp->next = temp->next->next;
            temp= temp->next;
        }
        return dummyNode->next;
    }
public:
    Node* copyRandomList(Node* head) {
        insertCopyBetween(head);
        connect(head);
        return getdeepcopy(head);
    }
};
