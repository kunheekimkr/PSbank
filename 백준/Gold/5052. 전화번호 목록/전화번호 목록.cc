// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct trie {
private:
    trie* children[10];
    bool isEnd = false;
public:

    trie(): children(){}
    
    void insert(string phonenum){
        trie* now = this;
        for(int i=0; i<phonenum.length(); i++) {
            if(now->children[phonenum[i]-'0'] == nullptr)
                now->children[phonenum[i]-'0'] = new trie();
            now = now->children[phonenum[i]-'0'];
            if(i == phonenum.length() -1)
                now -> isEnd = true;
        }
    }
    bool search(string phonenum){
        trie* now = this;
        for(int i=0; i<phonenum.length(); i++) {
            if(now->children[phonenum[i]-'0'] != nullptr) {
                now = now->children[phonenum[i]-'0'];
                if(now->isEnd)
                    return true;
            }
            else
                return false;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <string> phonenumlist(n);
        for (int i=0; i<n; i++) {
            cin >> phonenumlist[i];
        }
        
        sort (phonenumlist.begin(), phonenumlist.end());
        trie * tr = new trie();
        bool result = true;
        for (int i=0; i<n; i++) {
            string phonenum = phonenumlist[i];
            if(tr->search(phonenum)){
                result = false;
                break;
            }
            tr->insert(phonenum);
        }
        
        if(result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}