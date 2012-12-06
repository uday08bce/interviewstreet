#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct node{
    int value;
    set<int> next;
    bool mark;
    bool cycle;
    int distance;
};


vector<node> adj_list;
int start, point_end;

vector<int> paths;
map<int,int> paths_index;
bool cycle=false;
bool finish = false;

int count(int s, int e){
    set<int>::iterator it = adj_list[s].next.begin();
    for(; it != adj_list[s].next.end();++it){
        if( adj_list[(*it)].distance == -1){
            count((*it),e); 
        }
    }

    it = adj_list[s].next.begin();
    int total = 0;
    bool cycle = false;
    for(;it!=adj_list[s].next.end();++it){
        total = (total + adj_list[(*it)].distance) % 1000000000;
        if(adj_list[(*it)].cycle == true && adj_list[(*it)].distance != 0)
            cycle = true;

    }

    adj_list[s].distance = total;
    if(cycle)
        adj_list[s].cycle = true;
    
}

void remove_cycle(set<int> &s){
    // start point and end point is in a cycle
    if(s.find(point_end) != s.end() && s.find(start)!=s.end()){
        cout<<"INFINITE PATHS"<<endl;
        exit(0);
    }

    int replace = (*s.begin());
    if(s.find(point_end) != s.end())
        replace = point_end;

    set<int>::iterator it = s.begin();

    set<int> new_next;

    for(;it!=s.end();++it){
        new_next.insert( adj_list[(*it)].next.begin(), adj_list[(*it)].next.end());
        adj_list[(*it)].next.clear();
    }

    it = s.begin();
    for(;it!=s.end();++it){
        new_next.erase(*it);
    }

    adj_list[replace].next = new_next;
    adj_list[replace].cycle = true;
}

void dump(){
    for(int i=1;i<adj_list.size();i++){
        cout<<"node "<<adj_list[i].value<<" : ";
        set<int>::iterator it = adj_list[i].next.begin();
        for(;it!=adj_list[i].next.end();++it){
            cout<<(*it)<<" ";
        }
        cout<<endl;
        cout<<adj_list[i].distance<<" " << boolalpha << adj_list[i].cycle<<endl;
        
    }
}

void dfs(int pos){

    if(adj_list[pos].mark){
        //cout<<pos<<" has been marked"<<endl;
        // find a cycle
        set<int> s;
        int p = (*paths_index.find(pos)).second;
        for(int i =p; i< paths.size();i++){
            s.insert(paths[i]);
        }
        remove_cycle(s);
        cycle = true;

    }
    else{
        paths.push_back(pos);
        paths_index.insert(make_pair(pos,paths.size()-1));

        set<int>::iterator it = adj_list[pos].next.begin();

        adj_list[pos].mark = true;
        for(;it!=adj_list[pos].next.end() && ! cycle;++it){
            dfs((*it));
            adj_list[(*it)].mark = false;
        }
        if(!cycle)
            finish = true;
    }
}

int main(){
    int n,m;

    cin>>n>>m;

    start = 1; 
    point_end = n;
    adj_list.push_back(node()); // padding

    for(int i=0;i<n;i++){
        node n;
        n.value = i+1;
        n.mark = false;
        n.cycle = false;
        n.distance = -1;
        adj_list.push_back(n);
    }

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj_list[x].next.insert(y);
    }

 //   dump();
    // to remove all cycle
    while(!finish){
        dfs(1);
        cycle = false;
        paths.clear();
        paths_index.clear();
        for(int i=1;i<adj_list.size();i++)
            adj_list[i].mark = false;

       // dump();
    }
//    dump();
    adj_list[point_end].distance = 1;
    count(1,point_end);    
//    dump();
    if(adj_list[1].cycle)
        cout<<"INFINITE PATHS"<<endl;
    else if(adj_list[1].distance == -1)
        cout<<"0"<<endl;
    else
        cout<<adj_list[1].distance<<endl;

    return 0;
}
