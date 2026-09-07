class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        dp[0][0] = 0;

        for (int k = 0; k < n; k++) {
            vector<vector<int>> ndp = dp;

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {

                    if (dp[i][j] == -1)
                        continue;

                    // Increasing subsequence
                    if (i == 0 || arr[k] > arr[i - 1]) {
                        ndp[k + 1][j] =
                            max(ndp[k + 1][j], dp[i][j] + 1);
                    }

                    // Decreasing subsequence
                    if (j == 0 || arr[k] < arr[j - 1]) {
                        ndp[i][k + 1] =
                            max(ndp[i][k + 1], dp[i][j] + 1);
                    }
                }
            }

            dp = ndp;
        }

        int maximumUsed = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                maximumUsed = max(maximumUsed, dp[i][j]);
            }
        }

        return n - maximumUsed;
    }
};
