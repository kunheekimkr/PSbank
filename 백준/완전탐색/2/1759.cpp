#include<iostream>
#include<algorithm>
using namespace std;
int l,c;
char alphabet[15];
char word[15];

void backtracking(int cnt, int idx, int consonant, int vowel){
//cnt=만들어진 단어의 길이, idx= 가장 최근에 들어온 단어-> idx 이후의 글자들만 뒤에 붙일 수 있음 

    if(cnt==l){
        if(consonant >=2 && vowel >=1){ //문제 조건을 만족하는 단어일 경우 출력
            for(int i=0; i<l; i++)
                cout << word[i];
            cout << '\n';
            return;
        }
    }

    for(int i= idx+1; i<c; i++){ //idx 이후의 글자들에 대하여
        word[cnt]=alphabet[i]; //i번째 글자를 단어에 붙임
        if(alphabet[i]=='a' || alphabet[i]=='e' || alphabet[i]=='i' || alphabet[i]=='o' || alphabet[i]=='u')
            backtracking(cnt+1,i,consonant,vowel+1);
        else
            backtracking(cnt+1,i,consonant+1,vowel);
    }
}

int main(){
    cin >> l >> c;
    for(int i=0; i<c; i++){
        cin >> alphabet[i];
    }
    sort(alphabet,alphabet+c);
    backtracking(0,-1,0,0);

}