class Solution {
public:
    int minTime(vector<int>& duration, vector<vector<int>>& dependencies) {
        int n = duration.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build graph
        for (auto &edge : dependencies) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> dp = duration;

        // Nodes with no dependency
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int completed = 0;
        int answer = 0;

        // Topological sorting + longest path
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            completed++;
            answer = max(answer, dp[u]);

            for (int v : adj[u]) {
                dp[v] = max(dp[v], dp[u] + duration[v]);

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Cycle exists
        if (completed != n)
            return -1;

        return answer;
    }
};
