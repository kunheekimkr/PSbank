#include<iostream>
using namespace std;
int order;
int m,n;
int pieces1[1000],chosen1[2000001]={1,};
int pieces2[1000],chosen2[2000001]={1,};
int result=0;

void search(int num, int pieces[], int chosen[]){
    for(int i=1; i<=num;i++){ // i개의 연속한 조각을 뽑는 경우
        int sum=0;
        for (int j=0;j<i;j++)
            sum+=pieces[j]; //0번부터 i개 조각을 뽑음
        chosen[sum]++;
        if(i!=num)
            for(int j=1; j<num; j++){ //j번부터 i개 조각을 뽑음
                sum-=pieces[j-1];
                sum+=pieces[(j+i-1)%num];
                chosen[sum]++;
            }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> order >> m >> n;
    for (int i=0; i<m; i++)
        cin >> pieces1[i];
    for (int i=0; i<n; i++)
        cin >> pieces2[i];        
    search(m,pieces1,chosen1);
    search(n,pieces2,chosen2);

    for(int i=0; i<=order; i++){
        result+= chosen1[i]*chosen2[order-i];
    }
    cout << result;
}