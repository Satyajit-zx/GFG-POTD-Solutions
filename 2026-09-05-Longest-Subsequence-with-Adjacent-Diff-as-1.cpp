class Solution {
public:
    int longestSubseq(vector<int>& arr) {
        const int MAXV = 1000000;
        vector<int> dp(MAXV + 2, 0);

        int ans = 1;

        for (int x : arr) {
            int cur = 1 + max(dp[x - 1], dp[x + 1]);
            dp[x] = max(dp[x], cur);
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};
