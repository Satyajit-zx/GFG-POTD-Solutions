class Solution {
public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();

        vector<vector<int>> hor(n, vector<int>(n, 0));
        vector<vector<int>> ver(n, vector<int>(n, 0));

        // hor = consecutive X from left
        // ver = consecutive X from top
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 'X') {
                    hor[i][j] = 1;
                    ver[i][j] = 1;

                    if (j > 0)
                        hor[i][j] += hor[i][j - 1];

                    if (i > 0)
                        ver[i][j] += ver[i - 1][j];
                }
            }
        }

        int ans = 0;

        // Consider every cell as bottom-right corner
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (mat[i][j] != 'X')
                    continue;

                int small = min(hor[i][j], ver[i][j]);

                while (small > ans) {

                    // Top border and left border
                    if (hor[i - small + 1][j] >= small &&
                        ver[i][j - small + 1] >= small) {

                        ans = small;
                        break;
                    }

                    small--;
                }
            }
        }

        return ans;
    }
};
