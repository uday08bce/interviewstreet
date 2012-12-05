#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct node{
    int value;
    set<int> next;
    bool mark;
    bool is_cycle;
};

vector<node> vec;
vector<node> revert;
bool finish = false;
bool cycle = false; 

vector<int> paths;
map<int,int> record;


void dump(){
    cout<<"vec:"<<endl;
    for(int i=1;i<vec.size();i++){
        cout<<"node "<<vec[i].value<<" : ";
        set<int>::iterator it = vec[i].next.begin();
        for(;it!=vec[i].next.end();++it){
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }

    cout<<"revert:"<<endl;
    for(int i=1;i<revert.size();i++){
        cout<<"node "<<revert[i].value<<" : ";
        set<int>::iterator it = revert[i].next.begin();
        for(;it!=revert[i].next.end();++it){
            cout<<(*it)<<" ";
        }
        cout<<endl;
    }


}

// remove cycle

void dfs(int i){
    //cout<<"dfs "<<i<<endl;
    if(cycle)
        return;

    if(vec[i].mark == true){
//        cout<<i<<" has been tested!"<<endl;
        map<int,int>::iterator it = record.find(i);
        int start = (*it).second;
        int index = paths[start];
        set<int> temp;
        for(int j = start;j<paths.size();j++)
            temp.insert(paths[j]);

        set<int> vec_new;
        set<int> revert_new; 

        for(int j = start;j<paths.size();j++){
            int number = paths[j];    
            set<int>::iterator it = vec[number].next.begin();
            for(;it!=vec[number].next.end();++it){
                if(temp.find(*it) == temp.end())
                    vec_new.insert(*it);
            }
            vec[number].next.clear();
            
            // reset revert 
            set<int>::iterator it_r = revert[number].next.begin();
            for(;it_r!=revert[number].next.end();++it_r){
                if(temp.find(*it_r) == temp.end())
                    revert_new.insert(*it_r);
            }
            revert[number].next.clear();

        }


        revert[index].next = revert_new;
        vec[index].next = vec_new;
        vec[index].is_cycle = true;
        cycle = true;
    }
    else{
        vec[i].mark = true;
        paths.push_back(i);
        record.insert(make_pair(i, paths.size()-1));
        set<int>::iterator it = vec[i].next.begin();
        for(;it!=vec[i].next.end() && !cycle;++it){
            dfs(*it);
            vec[*it].mark = false;
        }
        if(!cycle)
            finish = true;
    }

}

int main(){
    int n,m;
    cin>>n>>m;

    // init
    vec.push_back(node());
    revert.push_back(node());
    for(int i=0;i<n;i++){
        node n;
        n.value = i+1;
        n.mark = false;
        n.is_cycle = false;
        vec.push_back(n);
        revert.push_back(n);
    }

    for(int i=0;i<m;i++){
        int x,y; 
        cin>>x>>y;
        vec[x].next.insert(y);
        revert[y].next.insert(x);
    }


//    dump();
    while(!finish){
        dfs(1);
        cycle = false;
        paths.clear();
        record.clear();

    }

 //   dump();
 
    return 0;
}
