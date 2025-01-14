class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>r( rowIndex+1,1);
        for(int i=1;i<rowIndex;i++){
             r[i]=r[i-1]*(long)((rowIndex+1)-i)/i;
        }
        return r;
    }
};
