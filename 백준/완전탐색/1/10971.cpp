#include<iostream>
using namespace std;
bool visited[10]={false,};
int n;
int arr[10][10];
int cost=10000000;
void search(int start, int current, int sum, int count){
    if(!visited[current]){
        visited[current]=true;
        for(int j=0;j<n;j++){
            if (arr[current][j]){
                search(start,j,sum+arr[current][j],count+1);
            }
        }
        visited[current]=false;
    }
    
    if(count==n && start== current){
        if(sum<cost)
            cost=sum;
    }

}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n;i++)
        search(i,i,0,0);
    cout << cost;
}