class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> freq;
        for (int x : power) freq[x]++;
        vector<int> vals;
        for (auto &p : freq) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        int n = vals.size();
        vector<long long> dp(n, 0);
        dp[0] = vals[0] * freq[vals[0]];

        for (int i = 1; i < n; i++) {
            long long take = (long long)vals[i] * freq[vals[i]];
            long long notTake = dp[i - 1];
            int j = i - 1;
            while (j >= 0 && vals[j] >= vals[i] - 2) j--;
            
            long long takeDamage = take + (j >= 0 ? dp[j] : 0);
            dp[i] = max(notTake, takeDamage);
        }

        return dp[n - 1];
    }
};
