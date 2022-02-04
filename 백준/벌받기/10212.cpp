#include<random>
#include<iostream>

using namespace std;
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,1);
    if(dis(gen))
        cout << "Korea";
    else
        cout << "Yonsei";
}