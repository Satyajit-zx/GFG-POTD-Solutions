class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Mark unsafe cells
        vector<vector<int>> safe = mat;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    safe[i][j] = 0;

                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];

                        if (nr >= 0 && nr < n &&
                            nc >= 0 && nc < m) {
                            safe[nr][nc] = 0;
                        }
                    }
                }
            }
        }

        // BFS
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Start from first column
        for (int i = 0; i < n; i++) {
            if (safe[i][0] == 1) {
                q.push({{i, 0}, 1});
                visited[i][0] = true;
            }
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int dist = curr.second;

            // Reached last column
            if (c == m - 1)
                return dist;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    safe[nr][nc] == 1 &&
                    !visited[nr][nc]) {

                    visited[nr][nc] = true;
                    q.push({{nr, nc}, dist + 1});
                }
            }
        }

        return -1;
    }
};
