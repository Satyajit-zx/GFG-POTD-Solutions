class Solution {
public:
    int findMinCost(string &s1, string &s2, int cost1, int cost2) {
        int n = s1.size();
        int m = s2.size();

        // Find LCS length
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        int lcs = prev[m];

        // Characters to delete from each string
        int del1 = n - lcs;
        int del2 = m - lcs;

        return del1 * cost1 + del2 * cost2;
    }
};
