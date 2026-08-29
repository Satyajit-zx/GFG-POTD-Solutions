class Solution {
public:
    int countSubsequences(string s, int n) {
        const int MOD = 1000000007;

        vector<int> dp(n, 0);

        for (char ch : s) {
            int digit = ch - '0';

            // Previous subsequences ko keep karo
            vector<int> curr = dp;

            // Current digit se ek new subsequence
            int r = digit % n;
            curr[r] = (curr[r] + 1) % MOD;

            // Existing subsequences ke end me current digit add karo
            for (int rem = 0; rem < n; rem++) {
                int newRem = (rem * 10 + digit) % n;

                curr[newRem] =
                    (curr[newRem] + dp[rem]) % MOD;
            }

            dp = curr;
        }

        return dp[0];
    }
};
