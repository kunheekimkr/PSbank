#include<iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> board1(5,5);
    vector<vector<int>> board(4,board1);
    vector<int> skill1={1,0,0,3,4,4};
    vector<int> skill2={1,2,0,2,3,2};
    vector<int> skill3={2,1,0,3,1,2};    
    vector<int> skill4={1,0,1,3,3,1};
    vector<vector<int>> skill={skill1,skill2,skill3,skill4};
    int arr[board.size()][board.at(0).size()];
    for(int i=0;i<board.size();i++){
        for(int j=0 ;j<board.at(0).size();j++){
            arr[i][j]=board.at(i).at(j);
        }
    }
    for(int i=0; i<skill.size(); i++){
        int type=skill.at(i).at(0);
        int r1=skill.at(i).at(1);
        int c1=skill.at(i).at(2);
        int r2=skill.at(i).at(3);
        int c2=skill.at(i).at(4);
        int degree=skill.at(i).at(5);
        for (int j=r1; j<=r2; j++){
            for(int k=c1; k<=c2; k++){
                if(type==1)
                    arr[j][k]-=degree;
                else
                    arr[j][k]+=degree;                    
            }
        }
    }
    int result=0;
    for(int i=0;i<board.size();i++){
        for(int j=0 ;j<board.at(0).size();j++){
            if(arr[i][j]>0)
                result++;
        }
    }
    cout << result;
}