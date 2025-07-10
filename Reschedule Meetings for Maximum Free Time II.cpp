class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> g(1, startTime[0]);
        for (int i = 1; i < startTime.size(); ++i)
            g.push_back(startTime[i] - endTime[i - 1]);
        g.push_back(eventTime - endTime.back());

        vector<int> largestRight(g.size(), 0);
        for (int i = g.size() - 2; i >= 0; --i)
            largestRight[i] = max(largestRight[i + 1], g[i + 1]);

        int ans = 0, largestLeft = 0;
        for (int i = 1; i < g.size(); ++i) {
            int curGap = endTime[i - 1] - startTime[i - 1];
            if (curGap <= max(largestLeft, largestRight[i]))
                ans = max(ans, g[i - 1] + g[i] + curGap);
            ans = max(ans, g[i - 1] + g[i]);
            largestLeft = max(largestLeft, g[i - 1]);
        }
        return ans;
    }
};
