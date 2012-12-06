#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;


struct node{
    set<int> neighbor; 
    bool isMachine;
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

bool ad

int main(){
    int n,k;
    cin>>n>>k;

    vector<node> adj_list;
    vector<edge> edges;

    for(int i=0;i<n;i++){
        node n;
        n.isMachine = false;
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
        adj_list[i].isMachine = true;
    }

    sort(edges.begin(),edges.end(),edge_cmp());

    return 0;
}
