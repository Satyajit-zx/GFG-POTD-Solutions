class Solution {
public:
    pair<int, int> bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farNode = start;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                v--;  // Houses are numbered 1 to n

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);

                    if (dist[v] > dist[farNode])
                        farNode = v;
                }
            }
        }

        return {farNode, dist[farNode]};
    }

    int partyHouse(vector<vector<int>>& adj) {
        // Find one end of diameter
        pair<int, int> first = bfs(0, adj);

        // Find the other end and diameter length
        pair<int, int> second = bfs(first.first, adj);

        int diameter = second.second;

        // Minimum maximum distance from a house
        return (diameter + 1) / 2;
    }
};
