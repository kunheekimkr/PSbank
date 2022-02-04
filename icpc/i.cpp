#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct contender{
    int num;
    int score;
    int tiebreak;
}contender;

vector< contender > result;

bool compare(contender &a, contender &b){

    if (a.score < b.score)
        return true;
    else if (a.score == b.score){
        if(a.tiebreak < b.tiebreak)
            return true;
        else if (a.tiebreak == b.tiebreak){
            if (a.num < b.num)
                return true;
            else 
                return false;
        }
        else
            return false;
    }
    else
        return false;
}

int main(){
    int n;
    cin >> n;
    
    while(n--){
        int num, s1,s2,s3;
        cin >> num >> s1 >> s2 >> s3;
        contender p;
        p.num=num;
        p.score=s1*s2*s3;
        p.tiebreak=s1+s2+s3;
        result.push_back(p);
    }
    
    sort(result.begin(),result.end(),compare);
    cout << result[0].num << ' ' << result[1].num << ' ' << result[2].num; 
}