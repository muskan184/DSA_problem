class Solution {
public:
    bool backtrack(vector<int>& nums, int index, vector<int>& subset, unordered_set<int>& used, long long product, long long target) {
        if (subset.size() > 0 && product == target) {
            long long otherProduct = 1;
            for (int i = 0; i < nums.size(); i++) {
                if (used.find(i) == used.end()) {
                    otherProduct *= nums[i];
                    if (otherProduct > target) return false;
                }
            }
            return otherProduct == target;
        }

        for (int i = index; i < nums.size(); i++) {
            long long newProduct = product * nums[i]; // Now safe
            if (newProduct > target) continue;

            subset.push_back(nums[i]);
            used.insert(i);
            if (backtrack(nums, i + 1, subset, used, newProduct, target)) return true;
            subset.pop_back();
            used.erase(i);
        }
        return false;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
       vector<int> subset;
    unordered_set<int> used;
    return backtrack(nums, 0, subset, used, 1, target); 
    }
};©leetcode
