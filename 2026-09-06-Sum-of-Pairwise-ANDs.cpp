class Solution {
public:
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
        long long ans = 0;

        for (int bit = 0; bit < 31; bit++) {
            long long cnt = 0;

            for (int x : arr) {
                if (x & (1LL << bit))
                    cnt++;
            }

            ans += cnt * (cnt - 1) / 2 * (1LL << bit);
        }

        return ans;
    }
};
