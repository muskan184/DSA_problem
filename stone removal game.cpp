class Solution {
public:
    bool canAliceWin(int n) {
        int count = 0;
        int pile = 10;

        while (n >= pile) {
            n -= pile;
            pile--;
            count++;
        }

        return count % 2 != 0;
    }
};
