class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;

        for (int num : nums1) {
            if (num == 0) zero1++;
            else sum1 += num;
        }

        for (int num : nums2) {
            if (num == 0) zero2++;
            else sum2 += num;
        }

        long long minVal1 = sum1 + zero1;
        long long minVal2 = sum2 + zero2;

        if (minVal1 == minVal2)
            return minVal1;

        if (minVal1 > minVal2) {
            long long diff = minVal1 - minVal2;
            if (zero2 > 0)
                return minVal1;
            else
                return -1;
        } else {
            long long diff = minVal2 - minVal1;
            if (zero1 > 0)
                return minVal2;
            else
                return -1;
        }
    }
};
