    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            int smallidx =i;
            for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallidx]){
                smallidx=j;
              }
            }
            swap(arr[i],arr[smallidx]);
        }
    }
