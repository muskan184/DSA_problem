class Solution {
public:
    bool issafe(int row,int col,vector<string> sol,int n){
        int duprow = row;
        int dupcol=col;
      

    while(row >=0 && col>=0){
        if(sol[row][col] == 'Q') return false;
        row--;
        col--;
    }
    col = dupcol;
    row = duprow;

    while(col>=0) {
        if(sol[row][col] == 'Q') return false;
        col--;
    }
    row = duprow;
    col = dupcol;

    while(row<n && col>=0){
        if(sol[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
    }
    void solve (int col,vector<string> &sol,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(sol);
            return;
        }
        for(int row=0;row<n;row++){
            if(issafe(row,col,sol,n)){
                    sol[row][col] = 'Q';
                 solve(col+1,sol,ans,n);
                  sol[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>sol(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            sol[i]=s;
        }
        solve(0,sol,ans,n);
        return ans;
    }
};
