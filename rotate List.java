class Solution {
       ListNode findNthNode(ListNode temp ,int k){
        int cnt =1;
        while(temp != null){
            if(cnt==k) return temp;
            cnt++;
            temp = temp.next;
        }
        return temp;
    }
    public ListNode rotateRight(ListNode head, int k) {
         if(head == null || k==0) return head;
        ListNode tail = head;
        int len =1;
        while(tail .next != null){
            tail=tail.next;
            len+=1;
        }
        if(k% len ==0) return head;
        k=k% len;
         tail.next =head;
         ListNode newlastNode = findNthNode(head,len-k);

         head= newlastNode.next;
         newlastNode.next=null;
         return head;
    }
}
