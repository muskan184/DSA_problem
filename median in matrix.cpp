  int upperBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int low=0;
        int high =n-1;
        
        while(low <= high ){
            int mid = (low+high)/2;
        
         if(arr[mid]>target){
             high=mid-1;
         }else{
             low=mid+1;
         }
        }
        return low;
    }
    
    int counSmallEqual(vector<vector<int>> &matrix, int n,int m,int x){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+= upperBound(matrix[i],x);
        }
        return cnt;
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m=mat[0].size();
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i=0;i<n;i++){
            low =min(low,mat[i][0]);
            high =max(high,mat[i][m-1]);
        }
        int req =(n*m)/2;
        while(low<=high){
            int mid =(low+high)/2;
            int smallEqual = counSmallEqual(mat,n,m,mid);
            if(smallEqual <= req) low=mid+1;
            else high=mid-1;
        }
            return low;
    }
