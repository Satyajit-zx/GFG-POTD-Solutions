class Solution {
public:
    long long dp[11][2][2];
    string s;
    int digit;

    long long solve(int pos, int tight, int started) {
        if (pos == s.size()) {
            return started ? 1 : 0;
        }

        long long &ans = dp[pos][tight][started];

        if (ans != -1)
            return ans;

        ans = 0;

        int limit = tight ? s[pos] - '0' : 9;

        for (int dig = 0; dig <= limit; dig++) {
            int newTight = tight && (dig == limit);
            int newStarted = started || (dig != 0);

            // If number has started, digit d cannot be used
            if (newStarted && dig == digit)
                continue;

            ans += solve(pos + 1, newTight, newStarted);
        }

        return ans;
    }

    int countWithout(int n, int d) {
        if (n <= 0)
            return 0;

        s = to_string(n);
        digit = d;

        memset(dp, -1, sizeof(dp));

        return solve(0, 1, 0);
    }
};
