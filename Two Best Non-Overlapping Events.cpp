class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());

        int n = events.size();

        vector<int>suffixMax(n);
        suffixMax[n-1]=events[n-1][2];

        for(int i=n-2;i>=0;i--){
            suffixMax[i]=max(suffixMax[i+1],events[i][2]);
        }

        int ans =0;
        for(int i=0;i<n;i++){
            int startTime=events[i][0];
            int endTime=events[i][1];
            int value=events[i][2];

            ans = max(ans,value);
            int left = i+1 , right= n-1;
            int nextIndex = -1;
            while(left<=right){
            int mid = (left+right)/2;

            if(events[mid][0] >= endTime+1){
                nextIndex=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
            if(nextIndex != -1){
                ans=max(ans,suffixMax[nextIndex]+value);
            }
        }
        return ans;
    }
};
