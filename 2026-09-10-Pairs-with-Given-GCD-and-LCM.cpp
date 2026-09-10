class Solution {
public:
    int pairCount(int x, int y) {
        // LCM must be divisible by GCD
        if (y % x != 0)
            return 0;

        int n = y / x;
        int distinct = 0;

        // Count distinct prime factors of n
        for (int p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                distinct++;

                while (n % p == 0)
                    n /= p;
            }
        }

        // Remaining prime factor
        if (n > 1)
            distinct++;

        // Each distinct prime factor can go to either a or b
        return 1 << distinct;
    }
};
