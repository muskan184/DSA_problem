class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end(),greater<int>());

        long long sum = 0;
        int curr = 0;

        for(int i=0;i<k;i++){
            int curr = happiness[i]-i;

            if(curr > 0){
                sum += curr;
            }else
            break;
        }
        return sum;
    }
};
