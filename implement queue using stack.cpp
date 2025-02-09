void MyQueue ::push(int x) {
    // Your Code
    if(rear == 100005) return;
    if(front == -1) front=rear=0;

        arr[rear]=x;
        rear+=1;
    
}

int MyQueue ::pop() {
    if(rear ==front) return -1;
// Function to pop an element from queue and return that element.
    
    int x=arr[front];
    front++;
    return x;
    // Your Code
}
