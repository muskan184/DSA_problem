class Solution {
public:
    int differenceOfSums(int n, int m) {
        int notDivisibleSum = 0, divisibleSum = 0;

        for (int i = 1; i <= n; i++) {
            if (i % m != 0) {
                notDivisibleSum += i;
            } else {
                divisibleSum += i;
            }
        }

        return notDivisibleSum - divisibleSum;

    }
};
