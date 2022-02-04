#include <iostream>
#include <algorithm>
using namespace std;
int n, l, k;
vector<int> coordinates;
vector<int> speeds;

typedef struct limit
{
    int coordinate;
    int speed;
} limit;

vector<int> limits;
int main()
{
    cin >> n >> l >> k;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        coordinates.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        speeds.push_back(tmp);
    }

    for (int i = 0; i < n; i++)
    {
        limit lm;
        lm.coordinate = coordinates[i];
        lm.speed = speeds[i];
        limits.push_back(lm);
    }

    while ()
}