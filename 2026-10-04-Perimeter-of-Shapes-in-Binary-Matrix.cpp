class Solution {
public:
    int findPerimeter(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int perimeter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    // Top
                    if (i == 0 || mat[i - 1][j] == 0)
                        perimeter++;

                    // Bottom
                    if (i == n - 1 || mat[i + 1][j] == 0)
                        perimeter++;

                    // Left
                    if (j == 0 || mat[i][j - 1] == 0)
                        perimeter++;

                    // Right
                    if (j == m - 1 || mat[i][j + 1] == 0)
                        perimeter++;
                }
            }
        }

        return perimeter;
    }
};
