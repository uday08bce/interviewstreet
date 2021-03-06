#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;


struct node{
    set<int> neighbor; 
    bool isMachine;
    bool visited;
};


struct edge{
    int i,j;
    int weight;
};

class edge_cmp{
    public:
        bool operator()(const edge &e1, const edge &e2){
            return e1.weight < e2.weight;
        }
};

vector<node> adj_list;
bool adj_machine(int pos){
    if(adj_list[pos].isMachine)
        return true;
    if(adj_list[pos].visited)
        return false;
    
    adj_list[pos].visited = true;
    bool found = false;
    set<int>::iterator it = adj_list[pos].neighbor.begin();
    for(;it!=adj_list[pos].neighbor.end();++it){
        if(adj_machine(*it)){
            found = true;
            break;
        }
    }
    adj_list[pos].visited = false;

    if(found)
        return true;
    else
        return false;
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<edge> edges;

    for(int i=0;i<n;i++){
        node n;
        n.isMachine = false;
        n.visited = false;
        adj_list.push_back(n);
    }

    for(int i=0;i<n-1;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj_list[x].neighbor.insert(y);
        adj_list[y].neighbor.insert(x);

        edge e;
        e.i=x;
        e.j=y;
        e.weight=w;

        edges.push_back(e);
    }
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        adj_list[temp].isMachine = true;
    }

    sort(edges.begin(),edges.end(),edge_cmp());
    int count = 0;
    long long total = 0;
    for(int i=0;i<edges.size() && count < k;i++){
        edge e = edges[i];
        adj_list[e.i].neighbor.erase(e.j);
        adj_list[e.j].neighbor.erase(e.i);
        if(adj_machine(e.i) && adj_machine(e.j)){
            count++;
            total+=e.weight;
        }
        else{
            adj_list[e.i].neighbor.insert(e.j);
            adj_list[e.j].neighbor.insert(e.i);
        }
    }

    cout<<total<<endl;

    return 0;
}
