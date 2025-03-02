class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;
            for (int j = i; j < i + k; j++) {
                if (!seen.count(nums[j])) {
                    freq[nums[j]]++;
                    seen.insert(nums[j]);
                }
            }
        }

        int result = -1;
        for (auto& [num, count] : freq) {
            if (count == 1) {
                result = max(result, num);
            }
        }
        return result;
    
}
};
