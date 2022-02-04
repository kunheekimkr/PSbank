#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string minname, maxname;
    int minday=1, minmonth=1, minyear=1990;
    int maxday=31, maxmonth=12, maxyear=2010;    
    while (n--){
    
        string name;
        int day, month, year;

        cin >> name >> day >> month >> year;
        
        
        if(year > minyear || (year==minyear && month > minmonth) || (year==minyear && month == minmonth && day > minday) ){
            minname = name;
            minday=day;
            minmonth=month;
            minyear=year;
        }
        
        
        
        if(year < maxyear || (year==maxyear && month < maxmonth) || (year==maxyear && month == maxmonth && day < maxday) ){
            maxname = name;
            maxday=day;
            maxmonth=month;
            maxyear=year;
        }
    }
    cout << minname << endl;
    cout << maxname;
}