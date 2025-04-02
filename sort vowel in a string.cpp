class Solution {
public:
    string sortVowels(string s) {
        vector<int> u(26, 0);
        vector<int> l(26, 0);
        string v = "AEIOUaeiou", ans = "";;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (v.find(c) != string::npos) {
                if (c >= 'a') l[c - 'a']++;
                else u[c - 'A']++;
                s[i] = '#';
            }
        }
        for (int i = 0; i < 26; i++) {
            while (u[i]--) {
                ans += 'A' + i;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (l[i]--) {
                ans += 'a' + i;
            }
        }
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (s[i] == '#') {
                s[i] = ans[j++];
            }
        }
        return s;
    }
};
