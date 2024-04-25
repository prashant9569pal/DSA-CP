
// Given an array arr of n integers, your task is to process queries of the following types :
//     update the value at position k to u
//         what is the minimum value in range[a, b]
//     ?
//     return an array containing answers for type 2 queries respectively.
//     Constraints :
//     1 <= n,
//     queries.length <= 10 ^ 5

//                                1 <= a <= b <= n

//                                1 <= u <= n

//                                1 <= arri,
//     u <= 10 ^ 9

//         Example :

//     Input

//         n = 8,
//         arr = [ 3, 2, 4, 5, 1, 1, 5, 3 ] queries = [
//             [ 2, 1, 4 ],
//             [ 2, 5, 6 ],
//             [ 1, 2, 3 ],
//             [ 2, 1, 4 ]
//         ] Output

//             [2, 1, 3]
#include <bits/stdc++.h>
using namespace std;

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
        if (start == end)
        {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);
        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
    }

    void build(vector<int> &v)
    {
        build(0, v.size() - 1, 0, v);
    }

    void update(int start, int end, int node, int index, int value)
    {
        if (start == end)
        {
            st[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            update(start, mid, 2 * node + 1, index, value);
        else
            update(mid + 1, end, 2 * node + 2, index, value);
        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
    }

    void update(int index, int value)
    {
        update(0, n - 1, 0, index, value);
    }

    int query(int start, int end, int l, int r, int node)
    {
        if (start > r || end < l)
            return INT_MAX;
        if (start >= l && end <= r)
            return st[node];
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);
        return min(q1, q2);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
};

vector<int> solve(int n, vector<int> arr, vector<vector<int>> queries)
{
    segmentTree tree;
    tree.init(n);
    tree.build(arr);
    vector<int> result;

    for (auto q : queries)
    {
        if (q[0] == 1) // Update query
            tree.update(q[1] - 1, q[2]);
        else if (q[0] == 2) // Minimum value in range query
            result.push_back(tree.query(q[1] - 1, q[2] - 1));
    }

    return result;
}

int main()
{
    int n = 8;
    vector<int> arr = {3, 2, 4, 5, 1, 1, 5, 3};
    vector<vector<int>> queries = {
        {2, 1, 4},
        {2, 5, 6},
        {1, 2, 3},
        {2, 1, 4}};

    vector<int> result = solve(n, arr, queries);

    // Print the result
    cout << "[";
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i];
        if (i < result.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
