class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnd = 0, minEnd = 0;
        int maxSum = 0, minSum = 0;

        for (int x : nums) {
            maxEnd = max(x, maxEnd + x);
            minEnd = min(x, minEnd + x);

            maxSum = max(maxSum, maxEnd);
            minSum = min(minSum, minEnd);
        }

        return max(maxSum, abs(minSum));
    }
};
