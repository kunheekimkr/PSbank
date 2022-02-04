#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int t;
int n, l;
vector<int> arr;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        arr.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        map<int, int> hmap;
        int min_distance = n;
        int previousIndex = 0, currentIndex = 0;
        for (int i = 0; i < n; i++)
        {

            if (hmap.find(arr[i]) != hmap.end())
            {
                currentIndex = i;
                previousIndex = hmap[arr[i]];
                min_distance = min((currentIndex - previousIndex), min_distance);
            }
            hmap[arr[i]] = i;
        }
        if (min_distance == n)
            min_distance = n + 1;

        cout << n - min_distance << '\n';
    }
}