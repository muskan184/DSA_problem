class Solution {
public:
    int triangularSum(vector<int>& nums) {
  int n = nums.size();

        // Pascal's triangle row build karenge modulo 10
        vector<int> coeff(n);
        coeff[0] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                coeff[j] = (coeff[j] + coeff[j-1]) % 10;
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + 1LL * nums[i] * coeff[i]) % 10;
        }

        return ans;
    }
};
