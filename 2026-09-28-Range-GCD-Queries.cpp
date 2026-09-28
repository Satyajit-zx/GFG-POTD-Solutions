class Solution {
public:
    vector<int> seg;

    int gcdValue(int a, int b) {
        return std::gcd(a, b);
    }

    void build(int node, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[node] = arr[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);

        seg[node] = gcdValue(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        seg[node] = gcdValue(seg[2 * node], seg[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        if (r < ql || l > qr)
            return 0;

        int mid = (l + r) / 2;

        int left = query(2 * node, l, mid, ql, qr);
        int right = query(2 * node + 1, mid + 1, r, ql, qr);

        return gcdValue(left, right);
    }

    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, arr);

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 0) {
                // Type 0: GCD of arr[l...r]
                int l = q[1];
                int r = q[2];

                ans.push_back(query(1, 0, n - 1, l, r));
            }
            else {
                // Type 1: arr[index] = value
                int idx = q[1];
                int val = q[2];

                update(1, 0, n - 1, idx, val);
            }
        }

        return ans;
    }
};
