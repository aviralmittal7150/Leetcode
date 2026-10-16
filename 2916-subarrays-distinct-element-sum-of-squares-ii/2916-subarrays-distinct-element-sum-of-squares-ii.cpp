
class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum1 = 0; // Sum of distinct counts
        long long sum2 = 0; // Sum of squared distinct counts
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sum2 =
            (tree[node].sum2 + 2LL * val * tree[node].sum1
             + len * val % MOD * val) % MOD;

        tree[node].sum1 =
            (tree[node].sum1 + len * val) % MOD;

        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, tree[node].lazy);
        apply(node * 2 + 1, mid + 1, r, tree[node].lazy);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;
        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node].sum1 =
            (tree[node * 2].sum1 + tree[node * 2 + 1].sum1) % MOD;

        tree[node].sum2 =
            (tree[node * 2].sum2 + tree[node * 2 + 1].sum2) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            // Distinct counts increase by 1 for subarrays
            // starting from prev + 1 through i.
            update(1, 0, n - 1, prev + 1, i, 1);

            ans = (ans + tree[1].sum2) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};
