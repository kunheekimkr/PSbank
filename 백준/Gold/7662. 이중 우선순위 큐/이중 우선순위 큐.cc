#include<iostream>
#include<set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        multiset<int> ms;
        while(n--) {
            char order;
            int num;
            cin >> order >> num;
            if(order == 'I') {
                ms.insert(num);
            } else {
                if (ms.empty()) {
                    continue;
                }
                if (num == 1) {
                    ms.erase(--ms.end());
                } else {
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.empty()) {
            cout << "EMPTY" << '\n';
        } else {
            cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
        }
    }
}