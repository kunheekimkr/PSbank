#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef struct student{
    string name;
    int korean;
    int english;
    int math;
}student;

bool compare (student a, student b){
    if(a.korean != b.korean)
        return (a.korean > b.korean);
    if(a.english != b.english)
        return (a.english < b.english);
    if(a.math != b.math)
        return (a.math > b.math);
    return (a.name < b.name);
}

int main(){
    int n;
    cin >> n;
    student arr[n];
    
    for(int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].korean >> arr[i].english >> arr[i].math;
    }

    sort(arr,arr+n,compare);
    for(int i=0; i<n; i++){
        cout << arr[i].name << '\n';
    }
}