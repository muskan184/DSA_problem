       Node merge (Node list1,Node list2){
        Node dummyNode = new Node(-1);
        Node res = dummyNode;
        while(list1 != null && list2 != null){
            if(list1.data < list2.data){
                res.bottom =list1;
                res=list1;
                list1=list1.bottom;
            }else{
                res. bottom =list2;
                res=list2;
                list2 = list2.bottom;
            }
            res.next=null;
        }
        if(list1 != null) res. bottom =list1;
        else res.bottom =list2;
        //if(dummyNode->bottom != NULL) dummyNode-> bottom >next=nullptr;
        
        return dummyNode. bottom ;
    }
    Node flatten(Node root) {
        if(root == null || root.next== null ) return root;
        Node  mergeHead = flatten(root.next);
        root =merge(root,mergeHead);
        return root;
  
    }
