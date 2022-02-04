#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b;
        vector<int> cnt(n + 1);
        set<int> st;
        for (int i = 0; i <= n + 1; i++)
        {
            st.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
            st.erase(a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            int now = *st.begin();
            set<int> temp;
            int j;
            for (j = 0; j < now; j++)
            {
                temp.insert(j);
            }

            for (j = i; j < n; j++)
            {
                temp.erase(a[j]);
                cnt[a[j]]--;
                if (cnt[a[j]] == 0)
                    st.insert(a[j]);
                if (temp.empty())
                    break;
            }
            i = j;
            b.push_back(now);
        }
        cout << b.size() << '\n';
        for (int i = 0; i < b.size(); i++)
            cout << b[i] << ' ';
        cout << '\n';
    }
}