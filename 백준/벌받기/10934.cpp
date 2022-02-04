#include<iostream>
#include<string>
#include<bitset>
#include<cmath>
using namespace std;
int leftrotate(int x,int c){
    return (x<<c)|(x>>32-c);
}
int main(){
    int r[64]={7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20, 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23, 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21};
    int k[64];
    int h0 = 0x67452301;
    int h1 = 0xEFCDAB89;
    int h2 = 0x98BADCFE;
    int h3 = 0x10325476;

    for(int i=0; i<65; i++ )
        k[i]=floor(abs(sin(i+1))*pow(2,32));
    string message;
    cin >> message;
    string binarystring;
    for(int i=0; i<message.size(); i++)
        binarystring += bitset<8>(message[i]).to_string();
    int p= binarystring.size();
    binarystring +='1';
    for(int i=0; binarystring.size()%512 !=448; i++)
        binarystring += '0';
    binarystring += bitset<64>(p).to_string();

    string w[16];
    for(int i=0; i<16; i++){
        w[i]=binarystring.substr(32*i,32);
    }
    int a=h0;
    int b=h1;
    int c=h2;
    int d=h3;
    int f,g;
    for (int i=0; i<64; i++){
        if(i<16){
            f=(b&c) | ((~b)&d);
            g=i;
        }
        else if (i<32){
            f=(d&b) | ((~d)&c);
            g=(5*i+1)%16;
        }
        else if (i<48){
            f=b^c^d;
            g=(3*i+1)%16;
        }
        else{
            f=c^(b|~d);
            g=(7*i)%16;
        }
        int temp=d;
        d=c;
        c=b;
        b+=leftrotate((a + f + k[i] + stoi(w[g],0,2)) , r[i]);
        a=temp;
    }
    h0 += a;
    h1 += b;
    h2 += c;
    h3 += d;   
    string hash= bitset<32>(h0).to_string()+bitset<32>(h1).to_string()+bitset<32>(h2).to_string()+bitset<32>(h3).to_string();
    cout << hash;
}
