#include<iostream>
int main(){
    int m=0, n=0;
    int sum=0, min=0;
    std::cin >> m ;
    std::cin >> n ;

    for(int i=n;i>=m;i--){
        for(int j=1; j<=1000; j++){
            if(j*j==i){
                min=i;
                sum+=i;
            }
        }
    }

    if( min !=0){
        std::cout << sum << std::endl;
        std::cout << min << std::endl;
    }
    else{
        std::cout << "-1" << std::endl;
    }
}