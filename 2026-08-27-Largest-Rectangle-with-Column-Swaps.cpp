class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> height(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Calculate heights
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            // Sort heights in descending order
            vector<int> temp = height;
            sort(temp.rbegin(), temp.rend());

            // Find maximum area
            for (int j = 0; j < m; j++) {
                ans = max(ans, temp[j] * (j + 1));
            }
        }

        return ans;
    }
};
