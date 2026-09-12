class Solution {
public:
    long long maxProduct(vector<int>& arr, int k) {
        int n = arr.size();

        // dpMax[j] = maximum product using j elements
        // dpMin[j] = minimum product using j elements
        vector<long long> dpMax(k + 1, LLONG_MIN);
        vector<long long> dpMin(k + 1, LLONG_MAX);

        dpMax[0] = dpMin[0] = 1;

        for (int x : arr) {
            for (int j = k; j >= 1; j--) {
                if (dpMax[j - 1] != LLONG_MIN) {
                    long long a = dpMax[j - 1] * x;
                    long long b = dpMin[j - 1] * x;

                    dpMax[j] = max(dpMax[j], max(a, b));
                    dpMin[j] = min(dpMin[j], min(a, b));
                }
            }
        }

        return dpMax[k];
    }
};
