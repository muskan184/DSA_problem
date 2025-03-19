class Solution {
public:
    int minOperations(vector<int>& no) {
        int n =no.size();
        int cnt=0;
        for(int i=2;i<n;i++){
            if(no[i-2]== 0){
                no[i-2]=!no[i-2];
                no[i-1]=!no[i-1];
                no[i]=!no[i];
                cnt++;
                
            }
        }
        for(int i=0;i<n;i++){
            if(no[i]==0) return -1;
        }
        return cnt;
    }
};
