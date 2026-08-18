class Solution {
public:
    
    void computeLPS(string &s, vector<int> &lps) {
        int n = s.size();
        lps[0] = 0;

        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];

            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1];
            }

            if (s[i] == s[len]) {
                len++;
            }

            lps[i] = len;
        }
    }

    string compress(string &s) {
        int n = s.size();

        vector<int> lps(n);
        computeLPS(s, lps);

        stack<char> st;

        for (int i = n - 1; i > 0; i--) {
            int len = i + 1;

            // Odd length cannot be divided into two equal halves
            if (len % 2 == 1) {
                st.push(s[i]);
                continue;
            }

            int longestPrefixSuffix = lps[i];
            int blockLength = len - longestPrefixSuffix;

            bool canCompress = false;

            if (longestPrefixSuffix * 2 >= len &&
                len % blockLength == 0 &&
                (len / blockLength) % 2 == 0) {
                canCompress = true;
            }

            if (canCompress) {
                st.push('*');

                // Continue with the first half
                i = len / 2;
            }
            else {
                st.push(s[i]);
            }
        }

        string ans;
        ans.push_back(s[0]);

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
