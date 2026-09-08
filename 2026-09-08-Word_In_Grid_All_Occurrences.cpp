#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();
        
        vector<vector<int>> result;
        
        // 8 possible directions: {row_change, col_change}
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        // Traverse each cell in the grid in lexicographical order (row-major)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the first character matches, check all 8 directions
                if (mat[i][j] == word[0]) {
                    bool found = false;
                    
                    for (int dir = 0; dir < 8; dir++) {
                        int r = i;
                        int c = j;
                        int k;
                        
                        for (k = 0; k < len; k++) {
                            // Out of bounds check
                            if (r < 0 || r >= n || c < 0 || c >= m) {
                                break;
                            }
                            
                            // Character mismatch check
                            if (mat[r][c] != word[k]) {
                                break;
                            }
                            
                            // Move in the chosen direction
                            r += dr[dir];
                            c += dc[dir];
                        }
                        
                        // If all characters matched
                        if (k == len) {
                            found = true;
                            break; // Stop checking other directions for this starting cell
                        }
                    }
                    
                    if (found) {
                        result.push_back({i, j});
                    }
                }
            }
        }
        
        return result;
    }
};
