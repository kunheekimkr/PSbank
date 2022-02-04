#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        int m, n;
        int r, c;
        cin >> m >> n >> r >> c;
        char arr[m][n];
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = str[j];
                if (arr[i][j] == 'B')
                    cnt++;
            }
        }

        if (cnt == 0)
        {
            cout << -1 << '\n';
            continue;
        }

        if (arr[r-1][c-1] == 'B')
        {
            cout << 0 << '\n';
            continue;
        }
        int temp = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[r-1][i] == 'B')
            {
                temp++;
                break;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (arr[i][c-1] == 'B')
            {
                temp++;
                break;
            }
        }
        if (temp == 0)
            cout << 2 << '\n';
        else
            cout << 1 << '\n';
    }
}