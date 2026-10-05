class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int> arr) {
        int n = arr.size() + 1;
        vector<vector<int>> ans;

        for (int i = 2; i <= n; i++) {
            int current = i;
            int links = 0;

            vector<pair<int, int>> temp;

            while (current != 1) {
                current = arr[current - 2];
                links++;

                temp.push_back({current, links});
            }

            // User number increasing order
            sort(temp.begin(), temp.end());

            for (auto p : temp) {
                ans.push_back({i, p.first, p.second});
            }
        }

        return ans;
    }
};
