          int count(Node slow,Node fast){
      int cnt=1;
      fast=fast.next;
      while(slow != fast){
          cnt++;
          fast=fast.next;
      }
      return cnt;
  }
    // Function to find the length of a loop in the linked list.
  public int countNodesinLoop(Node head) {
        // Code here
        Node slow=head;
      Node fast=head;
      while(fast!=null && fast.next!=null)
{      slow = slow.next;
      fast= fast.next.next;

      if(slow == fast) return count(slow,fast);
}
return 0;
    }
