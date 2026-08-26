class Solution {
public:
    bool isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<long long> dist(n, 0);
        vector<int> cnt(n, 0);
        vector<bool> inQueue(n, true);

        queue<int> q;

        // Start all vertices to detect cycles in disconnected components
        for (int i = 0; i < n; i++)
            q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (auto &[v, wt] : adj[u]) {
                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;

                    cnt[v]++;

                    // Vertex updated n times => negative cycle
                    if (cnt[v] >= n)
                        return true;

                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }

        return false;
    }
};
