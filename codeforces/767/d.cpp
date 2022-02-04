#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
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
        vector<string> arr(n);
        set<string> st;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            st.insert(arr[i]);
        }
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].size() == 1)
            {
                ans = true;
                break;
            }
            if (arr[i].size() == 2)
            {
                if (arr[i][0] == arr[i][1])
                {
                    ans = true;
                    break;
                }
            }
            if (arr[i].size() == 3 && arr[i][0] == arr[i][2])
            {
                ans = true;
                break;
            }
            if (arr[i].size() == 2)
            {
                if (st.find(arr[i].substr(1)) != st.end())
                {
                    ans = true;
                    break;
                }
                string temp = arr[i];
                reverse(temp.begin(), temp.end());
                if (st.find(temp) != st.end())
                {
                    ans = true;
                    break;
                }
                for (int i = 0; i < 26; i++)
                {
                    string c = "a";
                    c[0] += i;
                    temp = c + temp;
                    if (st.find(temp) != st.end())
                    {
                        ans = true;
                        goto X;
                    }
                }
            }
            if (arr[i].size() == 3)
            {
                if (arr[i][1] == arr[i][2])
                {
                    if (st.find(arr[i].substr(2)) != st.end())
                    {
                        ans = true;
                        break;
                    }
                }
                string temp = arr[i];
                reverse(temp.begin(), temp.end());
                if (st.find(temp.substr(1)) != st.end())
                {
                    ans = true;
                    break;
                }
                if (st.find(temp) != st.end())
                {
                    ans = true;
                    break;
                }
            }
            st.erase(arr[i]);
        }
    X:
        if (ans)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}