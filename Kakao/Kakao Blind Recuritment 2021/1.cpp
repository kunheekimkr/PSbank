#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string temp;
    cin >> temp;

    for(int i=0; i< temp.size(); i++){
        if(temp[i]>='A' && temp[i] <= 'Z')
            temp[i]=temp[i]-'A'+'a';
    } // 1단계
    cout << temp << endl;
    
    for(int i=0; i< temp.size(); i++){
        if ((temp[i]>='a' && temp[i] <= 'z') || (temp[i]>='0' && temp[i] <= '9') || temp[i]== '-' || temp[i]== '_' || temp[i]== '.'){
        }
        else
            temp[i]='!';
    } 
    temp.erase(remove(temp.begin(),temp.end(),'!'),temp.end());  //2단계
    cout << temp << endl;

    for(int i=0; i< temp.size(); i++){
        if (temp[i]=='.' && temp[i+1]=='.'){
            temp[i]='!';
        }
    } 
    temp.erase(remove(temp.begin(),temp.end(),'!'),temp.end());  //3단계
    cout << temp << endl; 

    if(temp[0]=='.')
        temp.erase(0,1);
    if(temp[temp.size()-1]=='.')
        temp.erase(temp.size()-1); // 4단계
    cout << temp << endl;

    if (temp == "")
        temp = "a"; // 5단계
    cout << temp << endl;

    if(temp.size()>=15)
        temp=temp.substr(0,15); // 6단계
    cout << temp << endl;

    if(temp.size()<=2){
        while(temp.size()!=3){
            temp+=temp[temp.size()-1];
        }
    } // 7단계

    cout << temp << endl;


}  