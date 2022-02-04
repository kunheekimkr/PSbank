#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int t, n;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> start(n - 1);
        vector<int> end(n - 1);
        vector<int> cnt(n + 1);
        vector<int> weight(n);
        vector<int> cntstart(n + 1);
        vector<int> cntend(n + 1);
        bool noanswer = false;
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            if (cnt[a] <= 1 && cnt[b] <= 1)
            {
                cnt[a]++;
                cnt[b]++;
                if (cntstart[a] == 0 && cntend[b] == 0)
                {
                    start[i] = a;
                    cntstart[a]++;
                    end[i] = b;
                    cntend[b]++;
                }
                else if (cntstart[a] == 0 && cntend[b] == 1)
                {
                    start[i] = b;
                    cntstart[b]++;
                    end[i] = a;
                    cntend[a]++;
                }
                else if (cntstart[a] == 1 && cntend[b] == 0)
                {
                    start[i] = b;
                    cntstart[b]++;
                    end[i] = a;
                    cntend[a]++;
                }
            }
            else
            {
                noanswer = true;
            }
        }
        if (noanswer)
            cout << -1 << '\n';
        else
        {
            int start = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (cnt[i] == 1)
                {
                    start = i;
                    break;
                }
            }
        }
    }
}