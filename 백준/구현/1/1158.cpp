#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    cout << '<';
    while (true){
        for(int i=0; i<k-1; i++){ //k의 배수번째가 아닌 수는 que의 제일 뒤로 보냄
            q.push(q.front());
            q.pop();
        }
        
        cout << q.front(); //k의 배수번쨰 숫자 제거
        q.pop();

        if(q.size()==0)
            break;
        cout << ", ";
    }
    cout << '>';
}