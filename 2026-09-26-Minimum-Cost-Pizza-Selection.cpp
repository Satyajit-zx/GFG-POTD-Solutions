class Solution {
public:
    int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
        int ans = 1000000000;

        for (int i = 0; i <= x / s + 1; i++) {
            for (int j = 0; j <= x / m + 1; j++) {

                int area = i * s + j * m;
                int k = 0;

                if (area < x) {
                    k = (x - area + l - 1) / l;
                }

                int cost = i * cs + j * cm + k * cl;

                ans = min(ans, cost);
            }
        }

        return ans;
    }
};
