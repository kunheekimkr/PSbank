#include<iostream>
#include<string>
using namespace std;
int main(){
    int n=3;
    while(n--){
        string s;
        cin >> s;
        int max=0;
        for(int j=0; j<s.size();j++){
            int cnt=1; 
            for(int k=j+1;k<s.size();k++){
                if(s[j]!=s[k])
                    break;
                cnt++;
            }
            if(cnt>max)
                max=cnt;
        }
        cout << max << '\n';
    }
}