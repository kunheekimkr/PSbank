#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, k;
        cin >> l >> r >> k;
        if (r - l == 0)
        {
            if (l == 1)
            {
                cout << "NO\n";
            }
            else
                cout << "YES\n";
        }

        else if (r - l == 1)
        {
            if (k > 0)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }

        else if (r - l == 2)
        {
            if (k == 2)
            {
                cout << "YES\n";
            }
            else if (k == 0)
            {
                cout << "NO\n";
            }
            else
            {
                if (l % 2 == 0)
                {
                    cout << "YES\n";
                }
                else
                    cout << "NO\n";
            }
        }

        else
        {

            if ((r - l + 1) % 2 == 0 && k >= (r - l + 1) / 2)
            {
                cout << "YES\n";
            }
            else if ((r - l + 1) % 2 == 1 && k > (r - l + 1) / 2)
            {
                cout << "YES\n";
            }
            else if ((r - l + 1) % 2 == 1 && k == (r - l + 1) / 2 && l % 2 == 0)
            {
                cout << "YES\n";
            }
            else
                cout << "NO\n";
        }
    }
}