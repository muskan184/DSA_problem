class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int maxKadane = INT_MIN, currentMax = 0;
        int minKadane = INT_MAX, currentMin = 0;

        for (int num : nums) {
            totalSum += num;

            currentMax = max(num, currentMax + num);
            maxKadane = max(maxKadane, currentMax);

            currentMin = min(num, currentMin + num);
            minKadane = min(minKadane, currentMin);
        }

        if (maxKadane < 0) return maxKadane; 
        return max(maxKadane, totalSum - minKadane);
    }
};
