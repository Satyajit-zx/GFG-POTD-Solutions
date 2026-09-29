class Solution {
public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Knight moves
        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

        // Convert 1-based to 0-based indexing
        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        if (sx == tx && sy == ty)
            return 0;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;

        q.push({{sx, sy}, 0});
        visited[sx][sy] = true;

        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    !visited[nx][ny]) {

                    if (nx == tx && ny == ty)
                        return steps + 1;

                    visited[nx][ny] = true;
                    q.push({{nx, ny}, steps + 1});
                }
            }
        }

        return -1;
    }
};
