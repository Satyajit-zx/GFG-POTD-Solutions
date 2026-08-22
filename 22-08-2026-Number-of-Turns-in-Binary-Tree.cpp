class Solution {
public:
    bool findPath(Node* root, int val, vector<char>& path) {
        if (root == NULL)
            return false;

        if (root->data == val)
            return true;

        // Left edge
        path.push_back('L');
        if (findPath(root->left, val, path))
            return true;
        path.pop_back();

        // Right edge
        path.push_back('R');
        if (findPath(root->right, val, path))
            return true;
        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int p, int q) {
        vector<char> pathP, pathQ;

        if (!findPath(root, p, pathP) ||
            !findPath(root, q, pathQ))
            return -1;

        // Find common path from root
        int i = 0;
        while (i < pathP.size() &&
               i < pathQ.size() &&
               pathP[i] == pathQ[i]) {
            i++;
        }

        // Build path from p to q
        vector<char> path;

        // p -> LCA
        for (int j = pathP.size() - 1; j >= i; j--)
            path.push_back(pathP[j]);

        // LCA -> q
        for (int j = i; j < pathQ.size(); j++)
            path.push_back(pathQ[j]);

        // No turn in the path
        if (path.size() <= 1)
            return -1;

        int turns = 0;

        for (int j = 1; j < path.size(); j++) {
            if (path[j] != path[j - 1])
                turns++;
        }

        return turns == 0 ? -1 : turns;
    }
};
