class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        for(auto d: dirs) {
            int nr = r + d[0], nc = c + d[1];
            if(nr >= 0 && nr < heights.size() && nc >=0 && nc < heights[0].size() 
               && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));
        
        // Pacific DFS
        for(int i=0;i<m;i++) dfs(heights, pac, i, 0);
        for(int j=0;j<n;j++) dfs(heights, pac, 0, j);
        
        // Atlantic DFS
        for(int i=0;i<m;i++) dfs(heights, atl, i, n-1);
        for(int j=0;j<n;j++) dfs(heights, atl, m-1, j);
        
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
