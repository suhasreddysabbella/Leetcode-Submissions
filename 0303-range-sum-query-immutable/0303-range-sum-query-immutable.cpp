class NumArray {
public:
    vector<int> segtree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();

        segtree.resize(4 * n);

        build(0, 0, n - 1, nums);
    }

    void build(int idx, int low, int high, vector<int>& nums) {

        // Leaf node
        if(low == high) {
            segtree[idx] = nums[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);

        segtree[idx] =
            segtree[2 * idx + 1] +
            segtree[2 * idx + 2];
    }

    int query(int idx, int low, int high,
              int l, int r) {

        // No overlap
        if(high < l || low > r)
            return 0;

        // Complete overlap
        if(low >= l && high <= r)
            return segtree[idx];

        // Partial overlap
        int mid = (low + high) / 2;

        int left =
            query(2 * idx + 1,
                  low,
                  mid,
                  l,
                  r);

        int right =
            query(2 * idx + 2,
                  mid + 1,
                  high,
                  l,
                  r);

        return left + right;
    }

    int sumRange(int left, int right) {

        return query(0, 0, n - 1, left, right);
    }
};