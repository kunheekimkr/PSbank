#include <iostream>
using namespace std;
int parent[1000001];

int find_root(int a){
    if (a == parent[a]) return a;
    return parent[a] = find_root(parent[a]);
}

void union_tree(int a, int b) {
    a = find_root(a);
    b = find_root(b);
    if (a!= b){
        parent[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    for (int i = 0; i < 1000001; i++)
        parent[i] = i;
        
    int n, m;
    cin >> n >> m;
    
    while(m--){
        int op,a,b;
        cin >> op >> a >> b;
        if (op == 0) {
            union_tree(a,b);
        } else {
            find_root(a) == find_root(b) ? cout << "YES\n" : cout << "NO\n";
        }
    }
}
