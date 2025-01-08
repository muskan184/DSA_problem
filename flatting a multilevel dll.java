
class Solution {
    public Node flatten(Node head) {
    Node temp=head;

        while(temp!=null){
            if(temp.child!=null){
                Node forward=temp.next;
                Node temp_child=temp;
                temp=temp.child;
                temp_child.child=null;
                temp_child.next=temp;
                temp.prev=temp_child;

                while(temp.next!=null){
                    temp=temp.next;
                }

                temp.next=forward;
                if(forward!=null) forward.prev=temp;
                temp=temp_child;
            }
            temp=temp.next;
        }

        return head;
    }
}
