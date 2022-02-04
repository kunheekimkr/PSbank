#include<iostream>
#include<vector>
using namespace std;
int arrows(int arr[], int a, int n){
    int sum=0;
    for(int i=0; i<a; i++)
        sum+=arr[i];
    return (n-sum);
}
int main(){
    int n=5;
    vector<int> info={2,1,1,1,0,0,0,0,0,0,0};
    int c[11];
    int answer[11];
    int max=0;
    bool result=false;
    for(c[0]=n; c[0] >=0; c[0]--){
        for(c[1]=arrows(c,1,n); c[1] >=0; c[1]--){
            for(c[2]=arrows(c,2,n); c[2] >=0; c[2]--){
                for(c[3]=arrows(c,3,n); c[3] >=0; c[3]--){
                    for(c[4]=arrows(c,4,n); c[4] >=0; c[4]--){
                        for(c[5]=arrows(c,5,n); c[5] >=0; c[5]--){
                            for(c[6]=arrows(c,6,n); c[6] >=0; c[6]--){
                                for(c[7]=arrows(c,7,n); c[7] >=0; c[7]--){
                                    for(c[8]=arrows(c,8,n); c[8] >=0; c[8]--){
                                        for(c[9]=arrows(c,9,n); c[9] >=0; c[9]--){
                                            c[10]=arrows(c,10,n);

                                            for(int i=0; i<11; i++){
                                                cout << c[i] << ' ';
                                            }
                                            cout << '\n';
                                            int ryan=0;
                                            int apeach=0;
                                            for(int i=0; i<=10; i++){
                                                if(c[i]>info.at(10-i))
                                                    ryan+=i;
                                                else if(c[i]==0 && info.at(10-i)==0){

                                                } 
                                                else
                                                    apeach+=i;
                                            }
                                            cout << ryan << ' ' << apeach << '\n';
                                            if(ryan>apeach){
                                                result=true;
                                                if(max<ryan-apeach){
                                                    max=(ryan-apeach);
                                                    for(int i=0; i<11; i++){
                                                        answer[i]=c[i];
                                                    }
                                                }
                                            }                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(result==false)
        cout << -1;
    else{
        for(int i=0; i<11; i++){
            cout << answer[i] << ' ';
        }
    }
}