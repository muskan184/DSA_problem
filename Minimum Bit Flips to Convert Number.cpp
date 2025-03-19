class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = start^goal;

        int ans =0;
        while(result >0){
            ans+=result & 1;
            result >>=1;
        }
        return ans;
    }
};
