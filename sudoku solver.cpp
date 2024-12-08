class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve (vector<vector<char>> &sol){
        for(int i=0;i<sol.size();i++){
            for(int j=0;j<sol[0].size();j++){

                if(sol[i][j] == '.'){
                    for(int row ='1';row<='9';row++){
                        if(isvalid ( sol,i,j,row)){
                            sol[i][j]= row;
                        if(solve(sol) == true) 
                            return true;
                        else
                            sol[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isvalid(vector<vector<char>> &sol,int row,int col,int c){
        for(int i=0;i<9;i++){
            if(sol[row][i]==c) return false;

            if(sol[i][col]==c) return false;

            if(sol[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
};
