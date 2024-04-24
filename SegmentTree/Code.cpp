#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct segmentTree
{
    int n;
    vector<int> st;
    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n);
    }
    void build(int start, int end, int node, vector<int> &v)
    {
        // leaf node
        if (start == end)
        {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        // left subtree is (start, mid)
        build(start, mid, 2 * node + 1, v);
        // right subtree is (mid+1, end)
        build(mid + 1, end, 2 * node + 2, v); // corrected the index for right child
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }
    void build(vector<int> &v)
    {
        build(0, v.size() - 1, 0, v);
    }
    int query(int start, int end, int l, int r, int node)
    {
        // non overlapping case
        if (start > r || end < l)
            return 0;
        // complete overlap case
        if (start >= l && end <= r)
            return st[node];
        // partial case
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);
        return q1 + q2;
    }
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
    void update(int start, int end, int node, int index, int value)
    {
        // basee case
        if (start == end)
        {
            st[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
        {
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            update(mid + 1, end, 2 * node + 2, index, value);
        }
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
        return;
    }
    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }
};

int32_t main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    segmentTree tree;
    tree.init(v.size());
    tree.build(v);
    cout << tree.query(0, 6) << endl;
    tree.update(2, 458);
    cout << tree.query(0, 5) << endl;
    return 0;
}