class Solution {
public:
    int dominantPairs(vector<int>& arr) {
        int n = arr.size();
        int mid = n / 2;
        
        vector<int> secondHalf(arr.begin() + mid, arr.end());
        
        // Sort second half for binary search
        sort(secondHalf.begin(), secondHalf.end());
        
        int ans = 0;
        
        for (int i = 0; i < mid; i++) {
            long long x = arr[i];
            
            // Need: arr[i] >= 5 * arr[j]
            // Find the first value y where 5*y > x
            // floor(x/5), handling negative numbers correctly.
            long long limit;
            
            if (x >= 0)
                limit = x / 5;
            else
                limit = -((-x + 4) / 5);
            
            // Number of elements <= limit
            ans += upper_bound(secondHalf.begin(),
                               secondHalf.end(),
                               limit) - secondHalf.begin();
        }
        
        return ans;
    }
};
