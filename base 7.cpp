class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        bool negative = false;
        if(num < 0){
            negative = true;
            num = -num;
        }

        string ans = "";
        while(num > 0){
            int rem = num % 7;
            ans.push_back(rem + '0');
            num = num / 7;
        }
        if(negative){
            ans.push_back('-');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
