#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
int arr[70];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (n <= 2)
        {
            cout << 0 << '\n';
            continue;
        }

        int ans = n;
        // 등비수열로 만들기 위해 필요한 최소 변환의 개수!
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cnt = 0;
                for (int k = 0; k < n; k++)
                {
                    if ((arr[i] - arr[k]) * (j - i) != (arr[j] - arr[i]) * (i - k))
                        cnt++;
                }
                ans = min(ans, cnt);
            }
        }
        cout << ans << '\n';
    }
}