class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
            int n = s.size();
        int m = p.size();
        if (m > n) return {}; 
        
        vector<int> freqP(26, 0);  
        vector<int> window(26, 0); 
        vector<int> result;

        for (char c : p) {
            freqP[c - 'a']++;
        }

        int i = 0, j = 0;
        while (j < n) {
            window[s[j] - 'a']++; 
            if (j - i + 1 > m) {
                window[s[i] - 'a']--;
                i++;
            }
            if (j - i + 1 == m && window == freqP) {
                result.push_back(i);
            }

            j++;
        }

        return result;
    }
};
