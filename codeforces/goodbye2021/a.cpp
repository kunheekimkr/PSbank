#include <iostream>
#include <cstring>
using namespace std;
int t;
int n;
int arr[101] = {
    0,
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (temp < 0)
                temp = -temp;
            arr[temp]++;
        }
        int ans = 0;
        if (arr[0] > 0)
        {
            ans++;
        }
        for (int i = 1; i < 100; i++)
        {
            if (arr[i] == 1)
            {
                ans++;
            }
            else if (arr[i] >= 2)
            {
                ans += 2;
            }
        }
        cout << ans << '\n';
        ans = 0;
        memset(arr, 0, sizeof(arr));
    }
}