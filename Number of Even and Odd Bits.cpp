class Solution {
public:
    vector<int> evenOddBit(int n) {
        bitset<12> bits(n);
        string str = bits.to_string();

        int even = 0, odd = 0;
        reverse(str.begin(), str.end());

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '1' and i % 2 == 0) {
                even++;
            } else if (str[i] == '1' and i % 2 != 0) {
                odd++;
            }
        }

        return {even, odd};
    }
};
