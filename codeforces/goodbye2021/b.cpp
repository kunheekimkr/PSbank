#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int t, n;
string str;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> str;

        if (n > 1 && str[0] == str[1])
        {
            cout << str[0] << str[0] << '\n';
            continue;
        }
        int i = 0;
        int j = 0;
        for (i = 1; i < n; i++)
        {
            if (str[i] > str[i - 1])
                break;
        }
        j = i - 1;
        for (i = 0; i <= j; i++)
        {
            cout << str[i];
        }
        for (i = j; i >= 0; i--)
        {
            cout << str[i];
        }
        cout << '\n';
    }
}