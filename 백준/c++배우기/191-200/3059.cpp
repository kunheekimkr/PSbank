#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int arr[26];
        for(int i=0;i<26;i++){
            arr[i]=0;
        }
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            arr[(int) (s[i]-'A')]++;
        }

        int sum=0;
        for(int i=0;i<26;i++){
            if(arr[i]==0)
                sum+=(int)'A' + i;
        }
        cout << sum << '\n';
    }
}