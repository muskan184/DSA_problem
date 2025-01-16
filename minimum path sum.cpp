class Solution {
    private:
    vector<vector<int>>dp;
    int h(vector<vector<int>>&grid, int i, int j){
        if(i == grid.size() - 1 && j == grid[0].size() - 1)
        return grid[i][j];
        if(i >= grid.size() || j >= grid[0].size())
        return INT_MAX;
        if(dp[i][j] != -1)
        return dp[i][j];
        int right =  h(grid, i, j + 1);
        int down = h(grid, i + 1, j);
        return  dp[i][j] = grid[i][j] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
        return h(grid, 0, 0);
    }
};
