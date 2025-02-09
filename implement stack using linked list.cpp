  private:
    StackNode *top;
    int size=0;

  public:
    void push(int x) {
        // code here
         StackNode* temp = new  StackNode(x);
         temp->next=top;
         top=temp;
         size=size+1;
         
    }

    int pop() {
        // code here
              if (top == nullptr) {
            return -1; 
        }
        int result = top->data; 
        StackNode* temp = top;  
        top = top->next;        
        delete temp;         
        size -= 1;
        return result;
    }
