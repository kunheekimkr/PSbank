//빨리 끝나는 회의를 최대한 배정하는 것이 최선의 알고리즘!
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct meeting{
    int start;
    int end;
}meeting;
bool compare(meeting a, meeting b){ //먼저 끝나는 회의가 우선이 되도록 정렬! 
    if(a.end!= b.end){
        return a.end < b.end;
    }
    else{
        return a.start < b.start;
    }
}
int main(){
    int n;
    cin >>n;
    vector <meeting> v;
    while(n--){
        int a,b;
        cin >> a >> b;
        meeting temp;
        temp.start=a;
        temp.end=b;
        v.push_back(temp);
    }
    sort(v.begin(),v.end(),compare);

    int cnt=0;
    int prev=0; //이전 회의가 끝난 시간 저장
    for(int i=0; i<v.size();i++){
        if (prev <= v[i].start){
            prev=v[i].end;
            cnt++;
        }
    }
    cout << cnt;
}