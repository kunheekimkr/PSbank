#include<iostream>
#include<string>
using namespace std;
string changebase(int n, int k){
    string temp="";
    while(n){
        temp+= to_string(n%k);
        n/=k;
    }
    string result="";
    for(int i=temp.size()-1; i>=0; i--){
        result+=temp[i];
    }
    return result;
}

bool isprime(unsigned long long s){
    if(s==0 || s==1)
        return false;
    else if(s==2 || s==3)
        return true;
    for(unsigned long long i=2; i*i<=s; i++){
        if(s%i==0)
            return false;
    }
    return true;
}

int main(){
    int n,k;
    cin >> n >> k;
    string str=changebase(n,k);
    int answer=0;
    while(str.size()>0){
        if(str.find("0")==string::npos){
            if(isprime(stoull(str))){
                answer++;
            }
            break;
        }
        string temp=str.substr(0,str.find("0"));
        if(isprime(stoull(temp))){
            answer++;
        }
        str=str.substr(str.find("0")+1,str.size());
        while(str[0]=='0'){
            str=str.substr(1,str.size());
        }
    }
    cout << answer;
}