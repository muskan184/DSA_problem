class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int odd=0;
        for(int i=0;i<n;i++){
            if(arr[i] % 2 !=0){
                 odd++;
            if(odd == 3)return true;
            }
        else odd=0;
        }
        return false;
    }
};
