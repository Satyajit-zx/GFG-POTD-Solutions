class Solution {
public:
    int minThrows(int n, vector<int>& ladders, vector<int>& snakes) {
        int total = n * n;

        vector<int> move(total + 1, -1);

        for (int i = 0; i + 1 < ladders.size(); i += 2) {
            move[ladders[i]] = ladders[i + 1];
        }

        for (int i = 0; i + 1 < snakes.size(); i += 2) {
            move[snakes[i]] = snakes[i + 1];
        }

        vector<int> dist(total + 1, -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == total)
                return dist[curr];

            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;

                if (next > total)
                    continue;

                if (move[next] != -1)
                    next = move[next];

                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};
