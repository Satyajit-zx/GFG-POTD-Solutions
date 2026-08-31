class Solution {
public:
    long long solve(int n, int i, int d, int c) {
        if (n == 0)
            return 0;

        // Only insert characters
        long long ans = 1LL * n * i;

        if (n == 1)
            return ans;

        // If n is even: directly copy-paste from n/2
        if (n % 2 == 0) {
            ans = min(ans, 1LL * c + solve(n / 2, i, d, c));
        }
        else {
            // Make n-1, copy-paste, then insert 1
            long long option1 =
                1LL * c + i + solve((n - 1) / 2, i, d, c);

            // Make n+1, copy-paste, then delete 1
            long long option2 =
                1LL * c + d + solve((n + 1) / 2, i, d, c);

            ans = min(ans, min(option1, option2));
        }

        return ans;
    }

    int minCost(int n, int i, int d, int c) {
        return (int)solve(n, i, d, c);
    }
};
