class Solution {
public:
    void dfs(Node* root, int level, vector<int>& costs) {
        if (root == NULL)
            return;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            costs.push_back(level);
            return;
        }

        dfs(root->left, level + 1, costs);
        dfs(root->right, level + 1, costs);
    }

    int getCount(Node* root, int k) {
        vector<int> costs;

        // Root is at level 1
        dfs(root, 1, costs);

        // Visit cheapest leaves first
        sort(costs.begin(), costs.end());

        int count = 0;

        for (int cost : costs) {
            if (k < cost)
                break;

            k -= cost;
            count++;
        }

        return count;
    }
};
