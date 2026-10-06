class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& dp, int n, int m) {
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 1;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];
            
            if (ni >= 0 && ni < n && nj >= 0 && nj < m &&
                matrix[ni][nj] > matrix[i][j]) {
                
                ans = max(ans, 1 + dfs(ni, nj, matrix, dp, n, m));
            }
        }
        
        return dp[i][j] = ans;
    }

    int longIncPath(vector<vector<int>>& matrix, int n, int m) {
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, matrix, dp, n, m));
            }
        }
        
        return ans;
    }
};
