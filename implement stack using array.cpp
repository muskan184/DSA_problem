void MyStack ::push(int x) {
    if(top>999) return;
    
    top=top+1;
    arr[top]=x;
}

int MyStack ::pop() {
    if(top == -1){
        return -1;
    } 
    
    int x=arr[top];
    top--;
    return x;
}
