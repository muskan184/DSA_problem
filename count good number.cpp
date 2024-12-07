class Solution {
public:
    const long long MOD = 1000000007;
    int exponention(int num, long long power) {

        // Exponention with iteration
        long long temp = num;
        long long res = 1;
        while (power > 0) {
            if (power & 1) {
                res = (res * temp)%MOD;
            }

            temp = (temp * temp)%MOD;
            power >>=1;
        }

        return res;
    }
    int countGoodNumbers(long long n) {
        if (n == 1) {
            return 5;
        }
        long long even_places = (n + 1) / 2;
        long long odd_places = n - even_places;

        long long iter1 = exponention(5, even_places);
        long long iter2 = exponention(4, odd_places);
        return (iter1 * iter2) % MOD;
    }
};
