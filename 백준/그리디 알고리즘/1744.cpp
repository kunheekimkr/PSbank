#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >>n;
    vector <long long> v;
    long long sum=0;
    for(int i=0; i<n; i++){
        long long temp;
        cin >> temp;
        if(temp !=1)
            v.push_back(temp);
        else
            sum +=1; // 1 은 다른 수랑 곱하는 것보다 혼자 더하는 것이 이득이므로 제외!
    }
    sort(v.begin(),v.end());
    int pos=0; //양수가 나오기 시작하는 지점
    for(int i=0; i<v.size(); i++){
        if(v[i]>0){
            pos=i;
            break;
        }
    }

    //음수*음수, 음수*0은 각각 더하는것 보다 이득이므로 작은 것부터 서로 곱해서 더함!
    if(pos%2==0){
        for(int i=0; i<pos; i+=2)
            sum+=v[i]*v[i+1];
    }
    else{
        for(int i=0; i<pos-1; i+=2)
            sum+=v[i]*v[i+1];
        sum+=v[pos-1];
    }

    //1보다 큰 양수들을 각각 더하는것보다 서로 곱하는 것이 이득이므로 큰것부터 서로 곱해서 더함!
    if((v.size()-pos)%2==0){
        for(int i=v.size()-1; i>pos; i-=2){
            sum+=v[i]*v[i-1];
        }
    }
    else{
        for(int i=v.size()-1; i>pos; i-=2){
            sum+=v[i]*v[i-1];
        }
        sum+=v[pos];
    }
    cout << sum;
}