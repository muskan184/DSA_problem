class Solution {
public:
    bool checkValidString(string s) {
    int n=s.length();
    int high =0;
    int low=0;

    for(char c:s){
        if(c == '('){
            low++;
            high++;
        } else if (c == ')') {
                low--, high--; 
            } 
            else {
                low--, high++;  
            }
            
            if (high < 0) return false;           
            if (low < 0) low = 0; 
        }
        
        return low == 0;
    }
};
