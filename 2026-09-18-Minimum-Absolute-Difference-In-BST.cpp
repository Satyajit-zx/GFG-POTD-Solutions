class Solution {
public:
    int ans;
    Node* prev;

    void inorder(Node* root) {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev != nullptr) {
            ans = min(ans, root->data - prev->data);
        }

        prev = root;

        inorder(root->right);
    }

    int absDiff(Node *root) {
        // Reset for every test case
        ans = INT_MAX;
        prev = nullptr;

        inorder(root);

        return ans;
    }
};
