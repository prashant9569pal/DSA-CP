#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX / 2;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;
        bool first = true;
        for (int i = 0; i < n; i++)
        {
            ans = max(arr[i] + ans, arr[i] * ans) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}