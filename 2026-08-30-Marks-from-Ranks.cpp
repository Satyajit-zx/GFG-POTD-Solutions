class Solution {
public:
    vector<int> getMarks(vector<int>& l1, vector<int>& r1, vector<int>& rank) {
        int n = l1.size();
        vector<long long> pref(n);
        
        // Number of valid marks up to each interval
        for (int i = 0; i < n; i++) {
            long long cnt = r1[i] - l1[i] + 1;
            pref[i] = cnt + (i > 0 ? pref[i - 1] : 0);
        }
        
        vector<int> ans;
        
        for (int k : rank) {
            // Find first interval having at least k marks
            int lo = 0, hi = n - 1;
            
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                
                if (pref[mid] >= k)
                    hi = mid;
                else
                    lo = mid + 1;
            }
            
            int i = lo;
            
            long long before = (i == 0 ? 0 : pref[i - 1]);
            
            // Position of kth mark inside this interval
            long long mark = l1[i] + (k - before - 1);
            
            ans.push_back((int)mark);
        }
        
        return ans;
    }
};
