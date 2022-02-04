#include<iostream>
#include<string>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

int count(vector<tuple<int, string, int>> p, string s){
    int cnt=0;
    for(int i=0;i<p.size();i++){
        if(get<1>(p.at(i))==s)
            cnt++;
    }
    return cnt;
}

int main(){
    vector<int> fees;
    vector<string> records;
    fees.push_back(180);
    fees.push_back(5000);
    fees.push_back(10);
    fees.push_back(600);
    records.push_back("05:34 5961 IN");
    records.push_back("06:00 0000 IN");
    records.push_back("06:34 0000 OUT");
    records.push_back("07:59 5961 OUT");
    records.push_back("07:59 0148 IN");
    records.push_back("18:59 0000 IN");
    records.push_back("19:09 0148 OUT");
    records.push_back("22:59 5961 IN");
    records.push_back("23:00 5961 OUT");

    vector<tuple<int, string, int>> carrecord;

    for(int i=0; i<records.size();i++){
        string temp=records.at(i);
        cout << temp << endl;
        temp=temp.substr(temp.find(" ")+1,temp.size());
        string carnum=temp.substr(0,temp.find(" "));
        
        temp=records.at(i);
        string hour=temp.substr(0,temp.find(":"));
        string minuite=temp.substr(temp.find(":")+1,temp.find(" "));
        int time=stoi(hour)*60+stoi(minuite);
        cout << time << endl;
        if(i==0)
            carrecord.push_back({time,carnum,1});
        else
            carrecord.push_back({time, carnum,count(carrecord,carnum)+1});
    }
    
    vector<pair<int, string>> timepercar;
    for(int i=0; i<carrecord.size(); i++){
        cout << get<0>(carrecord.at(i)) << ' ' << get<1>(carrecord.at(i)) << ' ' << get<2>(carrecord.at(i)) << '\n';
        if(get<2>(carrecord.at(i))==1)
            timepercar.push_back({-get<0>(carrecord.at(i)),get<1>(carrecord.at(i))});
        else {
            for(int j=0; j<timepercar.size();j++){
                if(timepercar.at(j).second==get<1>(carrecord.at(i))){
                    if(get<2>(carrecord.at(i))%2==0)
                        timepercar.at(j).first+=get<0>(carrecord.at(i));
                    else
                        timepercar.at(j).first-=get<0>(carrecord.at(i));
                }
            }
        }
    }


    int basictime=fees.at(0);
    int basicfee=fees.at(1);
    int unittime=fees.at(2);
    int addfee=fees.at(3);
    
    vector <pair<int, int>> feepercar;
    for(int i=0; i<timepercar.size();i++){
        if(timepercar.at(i).first<0)
            timepercar.at(i).first+=(60*23+59);
        cout <<timepercar.at(i).first << ' ' << timepercar.at(i).second << '\n';
        int time=timepercar.at(i).first;
        string carnum=timepercar.at(i).second;

        int price;
        if( time <= basictime)
            price=basicfee;
        else {
            price=basicfee;
            int addtime=time-basictime;
            if(addtime%unittime==0)
                price+= (addfee* (addtime/unittime));
            else
                price+= (addfee* ((addtime/unittime)+1));
        }

        feepercar.push_back({stoi(carnum),price});
    }

    sort(feepercar.begin(),feepercar.end());
    for(int i=0;i<feepercar.size();i++){
        cout <<feepercar.at(i).first << ' ' << feepercar.at(i).second << '\n';
    }
}