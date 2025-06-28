class Solution {
public:
    int dp[101][101]; 

    int mcm(vector<int>& arr, int i, int j) {
        // Base case
        if (i >= j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;

        for (int k = i; k < j; k++) {
            int costLeft = mcm(arr, i, k);
            int costRight = mcm(arr, k + 1, j);
            int costMultiply = arr[i - 1] * arr[k] * arr[j];

            int totalCost = costLeft + costRight + costMultiply;
            minCost = min(minCost, totalCost);
        }

        return dp[i][j] = minCost; 
    }

    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = -1;

        return mcm(arr, 1, n - 1);
    }
};
