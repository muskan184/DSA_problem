class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        vector<int> v(n - 1);
        
        for (int i = 1; i < n; i++) 
            v[i - 1] = original[i] - original[i - 1];

        int l = bounds[0][0], r = bounds[0][1];

        for (int i = 1; i < n; i++) {
            int nl = l + v[i - 1], nr = r + v[i - 1];
            l = max(nl, bounds[i][0]);
            r = min(nr, bounds[i][1]);

            if (l > r) return 0;
        }

        return r - l + 1;
    }
};
