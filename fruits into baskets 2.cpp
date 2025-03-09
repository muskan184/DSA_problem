class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        int m = b.size();
        int n = f.size();
        vector<int> p(m, 0);
        int cnt = 0;
        for(int i=0; i<n; i++) {
            bool placed = false;  
            for(int j=0; j<m; j++) {
                if (p[j] == 0 && b[j] >= f[i]) {
                    p[j] = 1;
                    placed = true;
                    break;  
                }
            }
            if (!placed) cnt++;
        }
        return cnt;
    }
};
