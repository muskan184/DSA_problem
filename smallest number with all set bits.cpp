class Solution {
public:
    int smallestNumber(int n) {
        int b = log2(n) + 1;           // Calculate the number of bits
        return (1 << b) - 1;          // Return 2^b - 1
    }
};
