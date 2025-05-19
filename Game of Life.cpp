class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        vector<vector<int>> res = board;

        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                int live = 0, dead = 0;
                
                if(i-1>=0){
                    if(board[i-1][j] == 0)dead++;
                    else live++;
                }
                
                if(i-1>=0 and j+1 < board[0].size()){
                    if(board[i-1][j+1] == 0)dead++;
                    else live++;
                }
                
                if(j+1 < board[0].size()){
                    if(board[i][j+1] == 0)dead++;
                    else live++;
                }
                
                if(i+1 < board.size() and j+1 < board[0].size()){
                    if(board[i+1][j+1] == 0)dead++;
                    else live++;
                }
                
                if(i+1 < board.size()){
                    if(board[i+1][j] == 0)dead++;
                    else live++;
                }
                
                if(i+1 < board.size() and j-1 >= 0){
                    if(board[i+1][j-1] == 0)dead++;
                    else live++;
                }
                
                if(j-1 >= 0){
                    if(board[i][j-1] == 0)dead++;
                    else live++;
                }
                
                if(i-1 >= 0 and j-1 >= 0){
                    if(board[i-1][j-1] == 0)dead++;
                    else live++;
                }
                
                if(live > 3 or live < 2){
                    res[i][j] = 0;
                }
                if(live == 3) res[i][j] = 1;
            }
        }
        board = res;
    }
};
