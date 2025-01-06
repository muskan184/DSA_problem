   Node * removeDuplicates(struct Node *head)
    {
        Node* temp =head;

while(temp!= NULL && temp->next != NULL) {

Node* nextNode =temp->next;

while(nextNode != NULL && nextNode->data== temp->data) {// Your code here
    Node* duplicate= nextNode;
    nextNode= nextNode->next;
free(duplicate);}
temp->next= nextNode;
if(nextNode !=NULL) nextNode->prev=temp;
temp=temp->next;}
return head;
    }
