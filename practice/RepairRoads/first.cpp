#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

struct node{
    node(){
        value = -1;
        father= -1;
        compute = false;
    }

    int value;
    int father;
    bool compute;
};


vector<node> v;

void init(){
    for(int i=0;i<10000;i++){
        node n;
        n.value=i;
        v.push_back(n);
    }
}

void reset(){
    for(int i=0;i<10000;i++){
        v[i].father = -1;
        v[i].compute = false;
    }
}


void exchange(int *i, int *y){
    int temp = *i;
    *i = *y;
    *y = temp;
}


int count(int n){
    set<int> root;
    for(int i=0;i<n;i++){

        node n = v[i];
        cout<<i<<" " << n.father <<endl;
        if(n.compute == false){
            while(n.father!=-1 && n.compute == false){
                n.compute = true;
                n = v[n.father];
            }
            if(n.father == -1)
                root.insert(n.value);
        }
    }

    /*
    copy(root.begin(),root.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    */

    return root.size();
}

int main(){
    int t;
    cin>>t;

    init();
    for(int i=0; i<t;i++){
        reset();
        int n;
        cin>>n;
        int x,y;
        for(int j=0;j<n-1;j++){
            cin>>x>>y;
            // make sure x <= y
            if(x>y)
                exchange(&x,&y);

            v[y].father= x;
        }
        cout<<count(n)<<endl;
    }
    return 0;
}
