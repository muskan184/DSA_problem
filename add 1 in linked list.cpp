      Node* reverseList(Node* head) {
        if(head == NULL || head->next==NULL){
            return head;
        }
    Node* prev = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
    }
    
    Node* addOne(Node* head) {
        head=reverseList(head);
        Node* temp= head;
        int carry =1;
        while(temp!=NULL){
            temp->data = temp->data+carry;
            if(temp->data <10){
                carry =0;
                break;
            }else{
                temp->data=0;
                carry=1;
            }
            temp=temp->next;
        }
        if(carry == 1){
            Node* newHead= new Node(1);
            head=reverseList(head);
            newHead->next=head;
            return newHead;
        }
        head=reverseList(head);
        return head;
    }
