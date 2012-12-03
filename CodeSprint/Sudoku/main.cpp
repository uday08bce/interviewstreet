#include <iostream>
#include <set>

using namespace std;
int board[9][9];

set<int> can[9][9];

set<int> get(int i, int j){
    set<int> result;
    for(int t=0;t<9;t++){
        if(t!=j)
            result.insert(board[i][t]);
        if(t!=i)
            result.insert(board[t][j]);
    }
    int row = (i/3)*3;
    int column = (j/3)*3;
    for(int k=row;k<row+3;k++){
        for(int m=column;m<column+3;m++){
            if(k!=i&&m!=j)
                result.insert(board[k][m]);
        }
    }
    return result;
}

void init(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] ==0){
                for(int t=1;t<10;t++)
                    can[i][j].insert(t);

                for(int t = 0;t<9;t++){
                    can[i][j].erase(board[i][t]);
                    can[i][j].erase(board[t][j]);
                }

                int row = (i/3)*3;
                int column = (j/3)*3;

                for(int k=row;k<row+3;k++){
                    for(int m=column;m<column+3;m++){
                        can[i][j].erase(board[k][m]);
                    }
                }
            }
        }
    }
}

bool conflict(int x, int y){ 
    set<int> result = get(x,y);
    if(result.find(board[x][y]) != result.end())
        return true;
    return false; 
}

bool solve(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j] == 0){
                set<int>::iterator it = can[i][j].begin();
                for(;it!=can[i][j].end();++it){
                    board[i][j] = (*it);

                    if(conflict(i,j)){
                        board[i][j] = 0;
                        continue;
                    }
                    else{
                        if(!solve()){
                            continue;
                        }
                        else{
                            return true;
                        }
                    }
                }
                return false;

            }
        }
    }
    return true;
}


int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cin>>board[i][j];
    }


    init();
    solve();

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
