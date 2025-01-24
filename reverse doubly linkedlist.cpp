    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
  if (!head || !head->next)
            return head;

        DLLNode* temp = nullptr;
        DLLNode* current = head;

        // Swap next and prev for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;  // Move to the next node (which is now prev)
        }

        // Before returning, update the head to the last node
        if (temp != nullptr)
            head = temp->prev;

        return head;
    }
