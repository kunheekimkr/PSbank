#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> id_list;
    vector<string> report;
    id_list.push_back("muzi");
    id_list.push_back("frodo");
    id_list.push_back("apeach");
    id_list.push_back("neo");
    report.push_back("muzi frodo");
    report.push_back("apeach frodo");
    report.push_back("frodo neo");
    report.push_back("muzi neo");
    report.push_back("apeach muzi");

    int members=id_list.size();
    int record[members][members]={0,0,0,0,};

    for (int i=0; i<report.size();i++){
        string r=report.at(i);
        string reporter=r.substr(0,r.find(" "));
        int numreporter;
        string reported=r.substr(r.find(" ")+1,r.size());
        int numreported;
        for(int j=0; j<members; j++){
            if(reporter == id_list.at(j))
                numreporter=j;
            if(reported == id_list.at(j))
                numreported=j;                
        }
        record[numreporter][numreported]++;
    } 

    int k=2;

    bool isstop[members];
    for(int i=0; i<members;i++){
        int result=0;
        for (int j=0; j<members; j++){
            if(record[j][i]>0)
                result++;
        }
        if(result>=k)
            isstop[i]= true;
        else
            isstop[i]=false;
    }

    vector<int> answer;
    for(int i=0; i<members; i++){
        int result=0;
        for (int j=0; j<members; j++){
            if(record[i][j]>0 && isstop[j]==true)
                result++;
        }
        answer.push_back(result);
    }

    for(int i=0; i<members; i++){
        cout << answer.at(i) << ' ';
    }
}