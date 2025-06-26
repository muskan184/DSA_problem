class Solution {
public:
    int minMovesToMakePalindrome(string s) {
         int n = s.length();
    int moves = 0;
    int left = 0, right = n - 1;

    while (left < right) {
        int l = right;
        while (s[l] != s[left]) {
            l--;
        }

        if (l == left) {
            swap(s[left], s[left + 1]);
            moves++;
        } else {
            for (int i = l; i < right; i++) {
                swap(s[i], s[i + 1]);
                moves++;
            }
            left++;
            right--;
        }
    }
    return moves;
    }
};
