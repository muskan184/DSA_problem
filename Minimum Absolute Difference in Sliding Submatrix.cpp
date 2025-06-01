class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for (int i = 0; i <= m - k; ++i) {
            for (int j = 0; j <= n - k; ++j) {
                vector<int> elements;
                
                
                for (int x = i; x < i + k; ++x) {
                    for (int y = j; y < j + k; ++y) {
                        elements.push_back(grid[x][y]);
                    }
                }

                sort(elements.begin(), elements.end());
                int minDiff = INT_MAX;
                for (int z = 1; z < elements.size(); ++z) {
                    if (elements[z] != elements[z - 1]) {
                        minDiff = min(minDiff, abs(elements[z] - elements[z - 1]));
                    }
                }

                ans[i][j] = (minDiff == INT_MAX ? 0 : minDiff);
            }
        }
        return ans;
    }
};
©leetcode
