#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> t(n * m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                t[i * m + j] = max(max(max(i + j, n - 1 - i + j), i + m - 1 - j), n - 1 - i + m - 1 - j);
            }
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < t.size(); i++)
            cout << t[i] << ' ';
        cout << '\n';
    }
}