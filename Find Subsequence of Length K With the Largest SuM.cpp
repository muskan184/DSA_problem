class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> withIndex;
        for (int i = 0; i < n; ++i) {
            withIndex.push_back({nums[i], i});
        }
        sort(withIndex.begin(), withIndex.end(), greater<pair<int, int>>());
        vector<pair<int, int>> topK(withIndex.begin(), withIndex.begin() + k);
        sort(topK.begin(), topK.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        vector<int> result;
        for (auto &p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};
