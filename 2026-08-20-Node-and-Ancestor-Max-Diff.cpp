class Solution {
public:
    pair<int, int> solve(Node* root) {
        if (root == NULL)
            return {INT_MAX, INT_MIN};

        auto left = solve(root->left);
        auto right = solve(root->right);

        int mn = min(root->data, min(left.first, right.first));

        int best = max(left.second, right.second);

        if (left.first != INT_MAX)
            best = max(best, root->data - left.first);

        if (right.first != INT_MAX)
            best = max(best, root->data - right.first);

        return {mn, best};
    }

    int maxDiff(Node* root) {
        return solve(root).second;
    }
};
