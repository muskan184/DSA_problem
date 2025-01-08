 Node* merge (Node *list1,Node* list2){
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(list1 != NULL && list2 != NULL){
            if(list1->data < list2->data){
                res-> bottom =list1;
                res=list1;
                list1=list1->next;
            }else{
                res-> bottom =list2;
                res=list2;
                list2 = list2->next;
            }
            res->next=nullptr;
        }
        if(list1) res-> bottom =list1;
        else res-> bottom =list2;
        //if(dummyNode->bottom != NULL) dummyNode-> bottom >next=nullptr;
        
        return dummyNode-> bottom ;
    }
    Node *flatten(Node *root) {
        if(root == NULL || root->next== NULL ) return root;
        Node * mergeHead = flatten(root->next);
        root =merge(root,mergeHead);
        return root;
    }
