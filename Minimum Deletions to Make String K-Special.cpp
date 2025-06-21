#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word)
            ++freq[c - 'a'];
        int ans = INT_MAX;
        for (int minFreq : freq) {              
            int deletions = 0;
            for (int f : freq) {
                if (f == 0) continue;             
                if (f < minFreq)               
                    deletions += f;
                else                           
                    deletions += max(0, f - (minFreq + k));
            }
            ans = min(ans, deletions);
        }
        return ans == INT_MAX ? 0 : ans;     
    }
};
