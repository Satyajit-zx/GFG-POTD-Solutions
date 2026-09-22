class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        // Store positions of every character
        vector<int> pos[26];

        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }

        string ans = "";

        for (string word : d) {
            int prev = -1;
            bool possible = true;

            for (char c : word) {
                vector<int>& v = pos[c - 'a'];

                // Find first occurrence after prev
                auto it = upper_bound(v.begin(), v.end(), prev);

                if (it == v.end()) {
                    possible = false;
                    break;
                }

                prev = *it;
            }

            if (possible) {
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};
