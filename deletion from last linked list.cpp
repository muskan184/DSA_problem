    Node *insertAtEnd(Node *head, int x) {
  if(head == NULL){
      return new Node(x);
  }
  Node* temp=head;
  while(temp->next!=NULL){
      temp=temp->next;
  }
  Node* newNode=new Node(x);
  temp->next=newNode;
  return head;
       
        
    }
