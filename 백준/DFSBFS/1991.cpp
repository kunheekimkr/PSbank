#include<iostream>
#include<vector>
using namespace std;
struct node{
    char left;
    char right;
};
vector<node> v(26);

void preorder(char node){
    if (node == '.')
        return;
    cout << node ;
    preorder(v[node].left);
    preorder(v[node].right);
}

void inorder(char node){
    if(node == '.')
        return;
    inorder(v[node].left);
    cout << node;
    inorder(v[node].right);
}

void postorder(char node){
    if(node == '.')
        return;
    postorder(v[node].left);
    postorder(v[node].right);
    cout << node;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char root, left, right;
        cin >> root >> left >> right;
        v[root].left=left;
        v[root].right=right;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

}
