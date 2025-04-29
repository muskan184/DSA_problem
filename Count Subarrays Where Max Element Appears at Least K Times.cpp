class Solution {
public:
        long long countSubarrays(vector<int>& nums, int k, int left = 0) {
        long maxi = *max_element(nums.begin(), nums.end()), maxiOcc = 0, count = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == maxi) {
                maxiOcc++;
            }
            while (maxiOcc >= k) {
                if (nums[left] == maxi) {
                    maxiOcc--;
                }
                left++;
            }
            count += left;
        }
        return count;
    }
};
