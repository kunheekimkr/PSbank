#include<iostream>
#include<string>
#include<bitset>
using namespace std;
int main(){
    string encode;
    cin >> encode;
    if(encode[encode.size()-1]=='=')
        encode.erase(encode.find('=')); // = padding 제거
    string binarystring;
    for(int i=0; i<encode.size();i++){
        int temp;
        if (encode[i]=='/')
            temp = 63;
        else if (encode[i] == '+')
            temp = 62;
        else if(encode[i]<=57)
            temp = encode[i] + 61 - '9';
        else if(encode[i]<=90)
            temp = encode[i] + 25 - 'Z';
        else
            temp = encode[i] + 51 - 'z';   
        binarystring += bitset<6>(temp).to_string();
    } // Decoding
    for(int i=0; binarystring.size()%8!=0;i++){
        binarystring.pop_back();
    } //0 padding 제거
    string decode;
    for(int i=0; i<binarystring.size()/8;i++){
        string temp= binarystring.substr(i*8,8);
        char c=stoi(temp,0,2);
        decode+=c;
    }//2진법수를 8자리씩 잘라 문자로 다시 변환
    cout << decode;
}