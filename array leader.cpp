        int n = arr.size();
        vector<int>ans;
        int maxRight = arr[n-1];
        
        ans.push_back(maxRight);
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]>=maxRight){
                maxRight=arr[i];
                ans.push_back(arr[i]);
            }
        }
        
    reverse(ans.begin(),ans.end());
        return ans;
    }
