    void printNos(int n) {
        int i=1;
        if(i>n){
            return;
        }
        printNos(n-1);
        cout<<n<" ";
        
    }
