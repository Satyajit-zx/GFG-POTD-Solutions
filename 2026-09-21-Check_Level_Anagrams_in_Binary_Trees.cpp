class Solution {
public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (root1 == NULL || root2 == NULL)
            return root1 == root2;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            // Both levels must have same number of nodes
            if (n1 != n2)
                return false;

            vector<int> level1, level2;

            for (int i = 0; i < n1; i++) {
                Node* cur = q1.front();
                q1.pop();

                level1.push_back(cur->data);

                if (cur->left)
                    q1.push(cur->left);

                if (cur->right)
                    q1.push(cur->right);
            }

            for (int i = 0; i < n2; i++) {
                Node* cur = q2.front();
                q2.pop();

                level2.push_back(cur->data);

                if (cur->left)
                    q2.push(cur->left);

                if (cur->right)
                    q2.push(cur->right);
            }

            // Order doesn't matter, so sort both levels
            sort(level1.begin(), level1.end());
            sort(level2.begin(), level2.end());

            if (level1 != level2)
                return false;
        }

        // Both trees should finish together
        return q1.empty() && q2.empty();
    }
};
