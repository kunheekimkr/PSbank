#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<int> a;
vector<int> b;
vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;

    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        a.clear();
        b.clear();
        int n, k;
        cin >> n >> k;
        a.resize(n);
        b.resize(n);
        v.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++)
        {
            v[i] = pair<int, int>(a[i], b[i]);
        }
        sort(v.begin(), v.end(), compare);
        for (int i = 0; i < n; i++)
        {
            if (k >= v[i].first)
                k += v[i].second;
            else
                break;
        }
        cout << k << '\n';
    }
}