class Solution {
public:
    int sameMod(vector<int> &arr) {
        int n = arr.size();

        // If all elements are equal
        bool same = true;

        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                same = false;
                break;
            }
        }

        if (same)
            return -1;

        // Find GCD of all differences
        int g = 0;

        for (int i = 1; i < n; i++) {
            g = gcd(g, abs(arr[i] - arr[0]));
        }

        // Count positive divisors of GCD
        int ans = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                ans++;

                if (i != g / i)
                    ans++;
            }
        }

        return ans;
    }
};
