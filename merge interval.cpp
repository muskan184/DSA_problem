class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if (n <= 0) return intervals;
        vector<vector<int>> ans;
        int s = intervals[0][0], max1 = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (max1 < intervals[i][0]) {
                ans.push_back({s, max1});
                s = intervals[i][0];
                max1 = intervals[i][1];
            } else {
                max1 = max(intervals[i][1], max1);
            }
        }
        ans.push_back({s, max1});
        return ans;
    }
};
