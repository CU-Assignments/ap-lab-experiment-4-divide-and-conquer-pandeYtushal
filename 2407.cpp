class SegTree
{
private:
    int tree_size;
    vector<int> tree;

    void update(int lx, int rx, int ni, int num, int val)
    {
        if (rx - lx == 1)
        {
            tree[ni] = max(tree[ni], val);
            return;
        }

        int m = (lx + rx) >> 1;

        if (num < m)
            update(lx, m, ni * 2 + 1, num, val);
        else
            update(m, rx, ni * 2 + 2, num, val);

        tree[ni] = max(tree[ni * 2 + 1], tree[ni * 2 + 2]);
    }

    int query(int l, int r, int lx, int rx, int ni)
    {
        if (lx >= r || rx <= l)
            return 0;

        if (l <= lx && rx <= r)
            return tree[ni];

        int m = (lx + rx) >> 1;
        return max(query(l, r, lx, m, ni * 2 + 1), query(l, r, m, rx, ni * 2 + 2));
    }

public:
    SegTree(int n)
    {
        tree_size = 1;

        while (tree_size < n)
            tree_size <<= 1;

        tree = vector<int>(tree_size * 2, 0);
    }

    void update(int num, int val)
    {
        update(0, tree_size, 0, num, val);
    }

    int query(int l, int r)
    {
        return query(l, r, 0, tree_size, 0);
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums, int k)
    {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        SegTree seg_tree(max_val + 1);

        for (const auto &num : nums)
        {
            int l = max(0, num - k), r = num - 1;
            int LIS = seg_tree.query(l, r + 1);
            seg_tree.update(num, LIS + 1);
        }

        return seg_tree.query(0, max_val + 1);
    }
};



Input: [4,2,1,4,3,4,5,8,15]
  Output: 5
