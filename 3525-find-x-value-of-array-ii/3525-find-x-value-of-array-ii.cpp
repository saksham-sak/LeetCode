class Solution {
public:
    struct Node {
        int prod;
        long long cnt[5];

        Node() {
            prod = 1;
            memset(cnt, 0, sizeof(cnt));
        }
    };

    int n, K;
    vector<Node> tree;

    Node merge(Node &a, Node &b) {
        Node c;

        c.prod = (a.prod * b.prod) % K;

        // Prefixes completely inside a
        for (int r = 0; r < K; r++) {
            c.cnt[r] += a.cnt[r];
        }

        // Prefixes that continue into b
        for (int r = 0; r < K; r++) {
            int rem = (a.prod * r) % K;
            c.cnt[rem] += b.cnt[r];
        }

        return c;
    }

    void build(vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            int rem = nums[l] % K;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = Node();

            int rem = val % K;
            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(node * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(node * 2 + 1, mid + 1, r, ql, qr);

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        n = nums.size();
        K = k;

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update persists
            update(1, 0, n - 1, index, value);

            // Get information from start to n-1
            Node temp = query(1, 0, n - 1, start, n - 1);

            ans.push_back(temp.cnt[x]);
        }

        return ans;
    }
};