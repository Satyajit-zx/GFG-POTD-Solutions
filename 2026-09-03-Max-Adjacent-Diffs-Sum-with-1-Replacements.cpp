class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        // dp[i][0]: index i par original element rakha hai
        // dp[i][1]: index i par element ko 1 se replace kiya hai
        vector<vector<int>> dp(n, vector<int>(2, 0));

        // Base case: index 0
        dp[0][0] = 0;
        dp[0][1] = 0;

        for (int i = 1; i < n; i++) {
            // Agar arr[i] ko original rakhein:
            dp[i][0] = max(
                dp[i - 1][0] + abs(arr[i] - arr[i - 1]),
                dp[i - 1][1] + abs(arr[i] - 1)
            );

            // Agar arr[i] ko 1 se replace karein:
            dp[i][1] = max(
                dp[i - 1][0] + abs(1 - arr[i - 1]),
                dp[i - 1][1] + abs(1 - 1)
            );
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
