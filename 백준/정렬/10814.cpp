#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

typedef struct member{
    int age;
    string name;
    int join; //가입 순서도 구조체 변수로 저장
} member;

bool compare(member a, member b){
    if(a.age >= b.age)
        return false;
    else
        return true;
}

int main(){
    int n;
    cin >> n;
    
    member arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].age >> arr[i].name;
        arr[i].join=i;
    }

    stable_sort(arr,arr+n,compare);

    for(int i=0; i<n; i++){
        cout << arr[i].age << ' ' << arr[i].name << '\n';
    }

}