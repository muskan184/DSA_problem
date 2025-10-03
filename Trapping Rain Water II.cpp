class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if(m == 0) return 0;
        int n = heightMap[0].size();
        
        // Min-Heap {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Step 1: Push all boundary cells into heap
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }
        
        // Directions for neighbors (up, down, left, right)
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int res = 0;
        int maxHeight = INT_MIN;

        // Step 2: Process heap
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            int h = cur[0], x = cur[1], y = cur[2];
            maxHeight = max(maxHeight, h);

            // Check neighbors
            for(auto &d : dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;

                visited[nx][ny] = true;

                // If neighbor lower → water trapped
                if(heightMap[nx][ny] < maxHeight){
                    res += maxHeight - heightMap[nx][ny];
                }

                // Push neighbor with maxHeight
                pq.push({heightMap[nx][ny], nx, ny});
            }
        }
        
        return res;
    }
};
