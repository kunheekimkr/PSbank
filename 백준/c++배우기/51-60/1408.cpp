#include<iostream>

int main(){
    int hour,minuite,second;
    scanf("%d:%d:%d",&hour,&minuite,&second);
    int starttime=hour*3600+minuite*60+second;
    scanf("%d:%d:%d",&hour,&minuite,&second);
    int endtime=hour*60*60+minuite*60+second;  
    if(endtime<starttime){
        endtime+=24*60*60;
    }
    int time=endtime-starttime;
    hour=time/3600;
    time%=3600;
    minuite=time/60;
    time%=60;
    second=time;
    printf("%02d:%02d:%02d",hour,minuite,second);
}