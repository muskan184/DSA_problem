class Spreadsheet {
public:
vector<vector<int>>grid;
    Spreadsheet(int rows) {
        grid = vector<vector<int>>(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
       int col = cell[0]-'A';
       int row = stoi(cell.substr(1))-1;

        grid[row][col] =value;

    }
    
    void resetCell(string cell) {
         int col = cell[0]-'A';
       int row = stoi(cell.substr(1))-1;

        grid[row][col] =0;
    }
    
    int getValue(string formula) {
        int ans =0;
        int i=1;
         while(formula[i] != '+'){
            i++;
         }
         string s= formula.substr(1,i-1);
         string s2 = formula.substr(i+1);

         if(isdigit(s[0])){
            ans+= stoi(s);
         }else{
        int col = s[0]-'A';
       int row = stoi(s.substr(1))-1;
       ans +=grid[row][col];
         }

         if(isdigit(s2[0])){
            ans+= stoi(s2);
         }else{
        int col = s2[0]-'A';
       int row = stoi(s2.substr(1))-1;
       ans +=grid[row][col];
         }

         return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
