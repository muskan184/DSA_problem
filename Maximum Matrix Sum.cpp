class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0 ;
        int negNum = 0 ;
        int mini = INT_MAX;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                int val = matrix[i][j];

                if(val < 0) negNum++;
                sum+= abs(val);
                mini = min(mini,abs(val));
            }
        }
        if(negNum % 2 == 1){
            sum -= 2LL* mini;
        }
        return sum;
    }
};
