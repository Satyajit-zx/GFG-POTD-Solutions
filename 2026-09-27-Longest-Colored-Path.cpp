class Solution {
public:
    int longestPath(string& s, vector<vector<int>>& edges) {
        int n = s.size();

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0] - 1;
            int v = e[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n, -1);
        vector<int> order;
        order.push_back(0);

        // Build parent array
        for (int i = 0; i < (int)order.size(); i++) {
            int u = order[i];

            for (int v : adj[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                order.push_back(v);
            }
        }

        // RR = longest R...R path starting from u
        // BB = longest B...B path starting from u
        // RB = longest R...R B...B path starting from u
        // BR = longest B...B R...R path starting from u
        vector<int> RR(n, 1), BB(n, 1);
        vector<int> RB(n, 0), BR(n, 0);

        int ans = 1;

        // Process children before parent
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (s[u] == 'R') {

                vector<pair<int, int>> red;
                vector<pair<int, int>> redBlue;

                for (int v : adj[u]) {
                    if (parent[v] != u)
                        continue;

                    if (s[v] == 'R') {
                        // R -> R...
                        red.push_back({1 + RR[v], v});

                        // R -> ... -> B
                        if (RB[v] > 0) {
                            redBlue.push_back({1 + RB[v], v});
                        }
                    }
                    else {
                        // R -> B...
                        redBlue.push_back({1 + BB[v], v});
                    }
                }

                sort(red.rbegin(), red.rend());
                sort(redBlue.rbegin(), redBlue.rend());

                // Only Red
                if (!red.empty())
                    RR[u] = red[0].first;

                // Red followed by Blue
                if (!redBlue.empty())
                    RB[u] = redBlue[0].first;

                // Two Red branches through u
                if (red.size() >= 2) {
                    ans = max(ans,
                              red[0].first + red[1].first - 1);
                }

                // Red branch + Red->Blue branch
                int best = 0;

                for (int a = 0; a < min(2, (int)red.size()); a++) {
                    for (int b = 0; b < min(2, (int)redBlue.size()); b++) {

                        // Both branches must be different
                        if (red[a].second != redBlue[b].second) {
                            best = max(best,
                                       red[a].first +
                                       redBlue[b].first - 1);
                        }
                    }
                }

                ans = max(ans, best);
                ans = max(ans, RR[u]);
                ans = max(ans, RB[u]);
            }

            else {

                vector<pair<int, int>> blue;
                vector<pair<int, int>> blueRed;

                for (int v : adj[u]) {
                    if (parent[v] != u)
                        continue;

                    if (s[v] == 'B') {
                        // B -> B...
                        blue.push_back({1 + BB[v], v});

                        // B -> ... -> R
                        if (BR[v] > 0) {
                            blueRed.push_back({1 + BR[v], v});
                        }
                    }
                    else {
                        // B -> R...
                        blueRed.push_back({1 + RR[v], v});
                    }
                }

                sort(blue.rbegin(), blue.rend());
                sort(blueRed.rbegin(), blueRed.rend());

                // Only Blue
                if (!blue.empty())
                    BB[u] = blue[0].first;

                // Blue followed by Red
                if (!blueRed.empty())
                    BR[u] = blueRed[0].first;

                // Two Blue branches through u
                if (blue.size() >= 2) {
                    ans = max(ans,
                              blue[0].first + blue[1].first - 1);
                }

                // Blue branch + Blue->Red branch
                int best = 0;

                for (int a = 0; a < min(2, (int)blue.size()); a++) {
                    for (int b = 0; b < min(2, (int)blueRed.size()); b++) {

                        // Both branches must be different
                        if (blue[a].second != blueRed[b].second) {
                            best = max(best,
                                       blue[a].first +
                                       blueRed[b].first - 1);
                        }
                    }
                }

                ans = max(ans, best);
                ans = max(ans, BB[u]);
                ans = max(ans, BR[u]);
            }
        }

        return ans;
    }
};
