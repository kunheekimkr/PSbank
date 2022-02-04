#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool includestring(string a, string b){
    int cnt=0;
    for(int i=0;i<b.size();i++) {
        if(a.find(b[i])!= string::npos)
            cnt++;
    }
    if(cnt==b.size())
        return true;
    else
        return false;
}

bool includechar(string a, char b){
    if(a.find(b)!= string::npos)
        return true;
    else
        return false;
}

int main(){
    vector<string> orders= {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    
    string alphabet="";
    for(int i=0; i<orders.size();i++){
        string s = orders.at(i);
        for(int j=0;j< s.size();j++){
            if(includechar(alphabet,s[j])){
            }
            else{
                alphabet+=s[j];
            }
        }
    }
    sort(alphabet.begin(),alphabet.end()); //메뉴 모두 저장
    

    vector<int> course = {2,3,4};

}