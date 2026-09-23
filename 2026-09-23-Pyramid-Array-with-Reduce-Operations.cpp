class Solution {
public:
    long long formPyramid(vector<int>& arr) {
        int n = arr.size();
        
        vector<long long> left(n), right(n);
        
        // Maximum possible height at each position
        // considering only the left side.
        left[0] = min(1LL, (long long)arr[0]);
        for (int i = 1; i < n; i++) {
            left[i] = min((long long)arr[i], left[i - 1] + 1);
        }
        
        // Considering only the right side.
        right[n - 1] = min(1LL, (long long)arr[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min((long long)arr[i], right[i + 1] + 1);
        }
        
        long long total = 0;
        long long maxPyramid = 0;
        
        for (int i = 0; i < n; i++) {
            total += arr[i];
            
            long long height = min(left[i], right[i]);
            
            // 1 + 2 + ... + h + ... + 2 + 1 = h^2
            maxPyramid = max(maxPyramid, height * height);
        }
        
        // Stones outside the chosen pyramid must be reduced to 0.
        return total - maxPyramid;
    }
};
