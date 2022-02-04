#include<iostream>
using namespace std;

int arr[100][100];

long long area(int lx, int ly, int rx, int ry){
    long long result=0;
    for(int i=ly; i<=ry; i++){
        for(int j=lx; j<=rx; j++){
            result+=arr[i][j];
        }
    }
    return result;
}

int main(){
    int n,m;
    cin >> n >> m;

    

    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            char temp;
            cin >>temp;
            arr[i][j]=temp-'0';
        }
    }

    long long sum=0;

    //case 1 세로로 두번 자르는 경우
    for(int i=0; i<m-2; i++){
        for(int j=i+1; j<m-1; j++){
            long long s1=area(0,0,i,n-1);
            long long s2=area(i+1,0,j,n-1);
            long long s3=area(j+1,0,m-1,n-1);
            if(sum<s1*s2*s3)
                sum=s1*s2*s3;            
        }
    }

    //case 2 가로로 두번 자르는 경우
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            long long s1=area(0,0,m-1,i);
            long long s2=area(0,i+1,m-1,j);
            long long s3=area(0,j+1,m-1,n-1);
            if(sum<s1*s2*s3)
                sum=s1*s2*s3;            
        }
    }

    //case 3 가로로 한번 자른 후 위쪽 조각을 세로로 자르는 경우
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            long long s1=area(0,0,i,j);
            long long s2=area(i+1,0,m-1,j);
            long long s3=area(0,j+1,m-1,n-1);
            if(sum<s1*s2*s3)
                sum=s1*s2*s3;            
        }
    }

    //case 4 가로로 한번 자른 후 아래쪽 조각을 세로로 자르는 경우    
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            long long s1=area(0,0,m-1,j);
            long long s2=area(0,j+1,i,n-1);
            long long s3=area(i+1,j+1,m-1,n-1);
            if(sum<s1*s2*s3)
                sum=s1*s2*s3;            
        }
    }

    //case 5 세로로 한번 자른 후 왼쪽 조각을 가로로 자르는 경우    
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            long long s1=area(0,0,i,j);
            long long s2=area(0,j+1,i,n-1);
            long long s3=area(i+1,0,m-1,n-1);
            if(sum<s1*s2*s3)
                sum=s1*s2*s3;            
        }
    }

    //case 6 세로로 한번 자른 후 오른쪽 조각을 가로로 자르는 경우    
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            long long s1=area(0,0,i,n-1);
            long long s2=area(i+1,0,m-1,j);
            long long s3=area(i+1,j+1,m-1,n-1);
            if(sum<s1*s2*s3)
                sum=s1*s2*s3;            
        }
    }
    cout << sum;
}