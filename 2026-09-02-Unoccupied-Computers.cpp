class Solution {
public:
    int solve(int n, string s) {
        bool occupied[26] = {false};
        bool rejected[26] = {false};
        int ans = 0;

        for (char c : s) {
            int id = c - 'A';

            if (!occupied[id] && !rejected[id]) {
                // First occurrence = arrival
                int used = 0;

                for (int i = 0; i < 26; i++) {
                    if (occupied[i])
                        used++;
                }

                if (used < n) {
                    occupied[id] = true;
                } else {
                    rejected[id] = true;
                    ans++;
                }
            } 
            else if (occupied[id]) {
                // Second occurrence = departure
                occupied[id] = false;
            }
        }

        return ans;
    }
};
