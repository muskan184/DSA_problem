 unordered_map<int, int> mp;
        int n = nums.size();

        // Count frequency of each number in the array
        for (int num : nums) {
            mp[num]++;
        }

        vector<int> result;

        // Check which numbers from 1 to n are missing
        for (int i = 1; i <= n; i++) {
            if (mp.find(i) == mp.end()) {
                result.push_back(i);
            }
        }

        return result;
