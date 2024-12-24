    bool searchKey(int n, struct Node* head, int key) {
    Node* temp= head;
    while(temp){
      if(temp->data == key) return 1;
           temp =temp->next;
    }
    return 0;
    }
