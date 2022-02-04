#include<iostream>
#include<cmath>
using namespace std;

int ax,ay,bx,by,cx,cy,dx,dy;

pair<double,double> minho(double p){ //p% 지점에서 민호의 위치
    return {ax+(bx-ax)*p/100, ay+(by-ay)*p/100};
}

pair<double,double> kangho(double p){ //p% 지점에서 강호의 위치 
    return {cx+(dx-cx)*p/100, cy+(dy-cy)*p/100};
}

int main (){

    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    double left=0;
    double right=100; //0~100%
    double ans=1000000000; //대충 큰 수
    //삼분탐색
    while(right-left>=1e-10){ 
        double l= (left*2+right)/3;
        double r= (left+right*2)/3;
        pair <double,double> ml = minho(l);
        pair <double,double> mr = minho(r);
        pair <double,double> kl = kangho(l);
        pair <double,double> kr = kangho(r);
        double distl=pow(ml.first-kl.first,2)+pow(ml.second-kl.second,2);
        double distr=pow(mr.first-kr.first,2)+pow(mr.second-kr.second,2);

        ans=min(ans,min(distl,distr));

        if(distl > distr)
            left=l;
        else
            right =r;
    }
    cout<< fixed;
    cout.precision(10);
    cout << sqrt(ans);

}