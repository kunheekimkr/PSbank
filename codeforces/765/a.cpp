#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int t;
int n, l;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> l;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i = 0; i < l; i++)
        {
            int zero = 0;
            int one = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] % 2 == 0)
                    zero++;
                else
                    one++;
                arr[j] /= 2;
            }
            if (one > zero)
                ans += pow(2, i);
        }
        cout << ans << '\n';
    }
}