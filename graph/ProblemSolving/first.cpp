#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct node{
    node(){
        level = 0;
        rating = 0;
        choosen = false;
    }
    int level;
    int rating;
    bool choosen;
};

vector<node> vec;

int n,k;

void init(){
    vec.resize(300);
    for(int i=0;i<300;i++){
        node elem;
        elem.level = i;
        vec.push_back(elem);
    }
}


void debug(int n){
    for(int i=0;i<n;i++){
        cout<<vec[i].rating<<" ";
    }
    cout<<endl;
}
void reset(){
    for(int i=0;i<300;i++){
        vec[i].choosen = false;
        vec[i].rating = 0;
    }
}


int solve(int n){
    int total = 0;
    for(int i=0;i<n;i++){
        if(vec[i].choosen == false){
            vec[i].choosen = true;
            node pre = vec[i];
            for(int j=i+1;j<n;j++){
                if(vec[j].choosen == false && abs(vec[j].rating - pre.rating) >= k){
                    vec[j].choosen = true;
                    pre = vec[j];
                }
            }
            total ++;
        }
    }
    return total;
}

int main(){
    int t;
    cin>>t;

    int rating;
    init();

    for(int i=0;i<t;i++){
        cin>>n>>k;

        for(int j=0;j<n;j++){
            cin>>rating;
            vec[j].rating = rating;
        }

        //debug(n);
        cout<<solve(n)<<endl;
        reset();

    
    }
    return 0;
}
