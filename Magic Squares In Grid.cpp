class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c){
        if(grid[r+1][c+1] != 5) return false;

        set<int> s;

        for(int i=r ;i<r+3;i++){
            for(int j=c;j<c+3;j++){
                if(grid[i][j] < 1 || grid[i][j] > 9) return false;
                s.insert(grid[i][j]);
            }
        }
        if(s.size() != 9) return false;

        int a=grid[r][c],b=grid[r][c+1],c1=grid[r][c+2];
        int d=grid[r+1][c],e=grid[r+1][c+1],f=grid[r+1][c+2];
        int g=grid[r+2][c],h=grid[r+2][c+1],i=grid[r+2][c+2];

        return 
         a+b+c1 == 15 &&
            d+e+f == 15 &&
            g+h+i == 15 &&
            a+d+g == 15 &&
            b+e+h == 15 &&
            c1+f+i == 15 &&
            a+e+i == 15 &&
            c1+e+g == 15;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
      int n =grid.size(), m=grid[0].size();
      int count =0;

      for(int i=0;i<=n-3;i++){
        for(int j=0;j<=m-3;j++){
            if(isMagic(grid,i,j)) count++;
        }
      }
      return count;
    }
};
