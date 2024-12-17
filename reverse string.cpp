class Solution {
public:
    void reverseString(vector<char>& s) {
        int h = s.size();
        for (int i = 0; i < s.size() / 2; i++) {

            int temp = s[i];
            s[i] = s[h - i - 1];
            s[h - i - 1] = temp;
        }
    }
};
