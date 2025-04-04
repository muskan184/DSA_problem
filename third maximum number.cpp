class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;
         
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > first) {
                first = nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != first && nums[i] > second) {
                second = nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != first && nums[i] != second && nums[i] > third) {
                third = nums[i];
            }
        }

        if (third == LLONG_MIN) {
            return (int)first;
        }

        return (int)third;
    }
};
