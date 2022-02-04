#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int max=0;
    while(n--){
        int arr[7];
        for(int i=1; i<7;i++){
            arr[i]=0;
        }
        
        for(int i=0; i<4; i++){
            int n;
            cin >> n;
            arr[n]++;
        }

        int point=0;
        for(int i=0; i<7; i++){
            if(arr[i]==4){
                point=50000+5000*i;
                break;
            }
            else if (arr[i]==3){
                point=10000+1000*i;
                break;
            }
            else if (arr[i]==2){
                int cnt=0;
                int temp;
                for(int j=i+1; j<7; j++){
                    if(arr[j]==2){
                        cnt++;
                        temp=j;
                    }
                }
                if(cnt==1){
                    point=2000+500*i+500*temp;
                    break;
                }
                else{
                    point=1000+100*i;
                    break;
                }
            }
            else if (arr[i]==1){
                int cnt=0;
                for(int j=i+1; j<7; j++){
                    if(arr[j]>0)
                        cnt++;
                }
                if(cnt==0){
                    point=i*100;
                }
            }
        }
        if(max<point)
            max=point;
    }    
    cout << max;
}