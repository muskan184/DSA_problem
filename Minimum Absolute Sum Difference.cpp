class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
          const int MOD = 1e9 + 7;
        int n = nums1.size();
        vector<int> sortedNums1(nums1);
        sort(sortedNums1.begin(), sortedNums1.end());

        long totalDiff = 0;
        int maxGain = 0;

        for (int i = 0; i < n; ++i) {
            int a = nums1[i];
            int b = nums2[i];
            int originalDiff = abs(a - b);
            totalDiff = (totalDiff + originalDiff) % MOD;
            auto it = lower_bound(sortedNums1.begin(), sortedNums1.end(), b);

            if (it != sortedNums1.end()) {
                maxGain = max(maxGain, originalDiff - abs(*it - b));
            }
            if (it != sortedNums1.begin()) {
                --it;
                maxGain = max(maxGain, originalDiff - abs(*it - b));
            }
        }

        return (totalDiff - maxGain + MOD) % MOD;
    }
};
