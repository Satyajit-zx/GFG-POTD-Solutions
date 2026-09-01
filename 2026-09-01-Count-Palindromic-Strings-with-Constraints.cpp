class Solution {
public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;
        
        long long ans = 0;
        long long perm = 1;
        
        for (int len = 1; len <= n; len++) {
            
            if (len % 2 == 1) {
                // Odd length
                int pairs = (len - 1) / 2;
                
                if (pairs == 0) {
                    ans = (ans + k) % MOD;
                } else {
                    perm = 1;
                    
                    // Choose distinct characters for pairs
                    for (int i = 0; i < pairs; i++) {
                        if (k - 1 - i < 0) {
                            perm = 0;
                            break;
                        }
                        perm = (perm * (k - 1 - i)) % MOD;
                    }
                    
                    ans = (ans + (k * perm) % MOD) % MOD;
                }
            } 
            else {
                // Even length
                int pairs = len / 2;
                
                perm = 1;
                
                for (int i = 0; i < pairs; i++) {
                    if (k - i <= 0) {
                        perm = 0;
                        break;
                    }
                    perm = (perm * (k - i)) % MOD;
                }
                
                ans = (ans + perm) % MOD;
            }
        }
        
        return ans;
    }
};
