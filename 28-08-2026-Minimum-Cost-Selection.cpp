class Solution {
public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();

        vector<int> dp = mat[0];

        for (int i = 1; i < n; i++) {
            vector<int> curr(3);

            curr[0] = mat[i][0] + min(dp[1], dp[2]);
            curr[1] = mat[i][1] + min(dp[0], dp[2]);
            curr[2] = mat[i][2] + min(dp[0], dp[1]);

            dp = curr;
        }

        return min({dp[0], dp[1], dp[2]});
    }
};
