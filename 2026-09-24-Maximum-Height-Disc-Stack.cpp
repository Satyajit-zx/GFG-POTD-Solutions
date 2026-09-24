class Solution {
public:
    int maxStackHeight(vector<int> &r, vector<int> &h) {
        int n = r.size();

        vector<pair<int, int>> discs;

        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
        }

        // Sort by radius
        sort(discs.begin(), discs.end());

        // Coordinate compression of heights
        vector<int> heights = h;
        sort(heights.begin(), heights.end());
        heights.erase(unique(heights.begin(), heights.end()), heights.end());

        int m = heights.size();

        // Fenwick Tree for maximum value
        vector<int> bit(m + 1, 0);

        auto query = [&](int idx) {
            int ans = 0;
            while (idx > 0) {
                ans = max(ans, bit[idx]);
                idx -= idx & -idx;
            }
            return ans;
        };

        auto update = [&](int idx, int value) {
            while (idx <= m) {
                bit[idx] = max(bit[idx], value);
                idx += idx & -idx;
            }
        };

        int answer = 0;

        int i = 0;

        while (i < n) {
            int j = i;

            // Same radius must not be stacked together
            while (j < n && discs[j].first == discs[i].first) {
                j++;
            }

            vector<pair<int, int>> pending;

            for (int k = i; k < j; k++) {
                int height = discs[k].second;

                int pos = lower_bound(
                    heights.begin(),
                    heights.end(),
                    height
                ) - heights.begin() + 1;

                // Strictly smaller height
                int best = query(pos - 1);

                int current = best + height;

                pending.push_back({pos, current});

                answer = max(answer, current);
            }

            // Update only after processing the complete radius group
            for (auto &p : pending) {
                update(p.first, p.second);
            }

            i = j;
        }

        return answer;
    }
};
