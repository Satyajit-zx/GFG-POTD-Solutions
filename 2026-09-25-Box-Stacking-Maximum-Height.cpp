class Solution {
public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        int n = height.size();

        // {base length, base width, height}
        vector<array<int, 3>> boxes;

        for (int i = 0; i < n; i++) {

            // Rotation 1
            boxes.push_back({
                max(width[i], length[i]),
                min(width[i], length[i]),
                height[i]
            });

            // Rotation 2
            boxes.push_back({
                max(height[i], length[i]),
                min(height[i], length[i]),
                width[i]
            });

            // Rotation 3
            boxes.push_back({
                max(height[i], width[i]),
                min(height[i], width[i]),
                length[i]
            });
        }

        // IMPORTANT: use long long to avoid overflow
        sort(boxes.begin(), boxes.end(), [](const auto &a, const auto &b) {
            long long areaA = 1LL * a[0] * a[1];
            long long areaB = 1LL * b[0] * b[1];

            return areaA < areaB;
        });

        int m = boxes.size();

        // dp[i] = maximum height with box i at the bottom
        vector<int> dp(m);

        int ans = 0;

        for (int i = 0; i < m; i++) {
            dp[i] = boxes[i][2];

            for (int j = 0; j < i; j++) {

                // Box j can be placed on box i
                if (boxes[j][0] < boxes[i][0] &&
                    boxes[j][1] < boxes[i][1]) {

                    dp[i] = max(dp[i],
                                boxes[i][2] + dp[j]);
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
