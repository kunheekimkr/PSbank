#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    string answer;
    cin >> n;
    if(n == 0 || n == 1) 
        cout << n;
    else{
        while (n!=0){
            if(n%2==0){
                answer+="0";
                n=-n/2;
            }
            else{
                answer+="1";
                if(n>0)
                    n= -(n/2);
                else 
                    n= (-n+1)/2;
            }
        }
        for(int i=answer.size()-1; i>=0; i--)
            cout << answer[i];
    }
}