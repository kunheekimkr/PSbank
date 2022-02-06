#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int arr[9] = {0,};
bool visited[9] = {false,};
vector<int> v;
void dfs(int num, int cnt){
    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int temp=0;
    for(int i=num; i<n; i++){
        if((visited[i] == false || num ==i) && v[i] != temp){
            arr[cnt] = v[i];
            temp = arr[cnt];
            visited[i] = true;
            dfs(i, cnt+1);
            visited[i] = false;
        }
    }

}

int main(){
    cin >> n >> m;
	v.resize(n);
    for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	dfs(0,0);
}