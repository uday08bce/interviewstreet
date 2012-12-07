#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <set>

using namespace std;


struct node{
    set<int> neighbour; 
    bool isMachine;
    bool visited;
    int number;
    int father;
    set<int> children;
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

void build(){
    //  adj_list[0] is the root
    adj_list[0].father = -2;
    queue<int> q;
    q.push(0);
    adj_list[0].visited = true;
    while(!q.empty()){  
        int i = q.front();
        q.pop();
        set<int>::iterator it = adj_list[i].neighbour.begin();
        for(;it!=adj_list[i].neighbour.end();++it)
        {
            if(adj_list[*it].visited)
                continue;
            adj_list[*it].visited = true;
            adj_list[*it].father = i;
            q.push(*it);
            adj_list[i].children.insert(*it);
        }
    }
}

int countMachine(int pos){
    if(adj_list[pos].number != -1){
        return adj_list[pos].number;
    }

    set<int>::iterator it = adj_list[pos].children.begin();
    int total = 0;
    for(;it!=adj_list[pos].children.end();++it){
        total += countMachine(*it);
    }

    if(adj_list[pos].isMachine)
        total++;
    adj_list[pos].number= total;
    return total;
}

void order(int &i,int &j){
    if(adj_list[j].father == i)
        return ;
    else{
        int temp = i;
        i = j;
        j = temp;
    }
}

int number(int pos){
    int total = 0;
    set<int>::iterator it = adj_list[pos].children.begin();
    for(;it!=adj_list[pos].children.end();++it){
        total += adj_list[*it].number;
    }

    if(adj_list[pos].isMachine)
        total++;

    return total;
}

void change(int pos, int number){
    while(pos != -2){
        adj_list[pos].number -= number;
        pos = adj_list[pos].father;
    }
}

void dump(){
    for(int i=0;i<adj_list.size();i++){
        cout<<"node "<<i;
        cout<<" number "<<adj_list[i].number;
        cout<<" children ";
        set<int>::iterator it = adj_list[i].children.begin();
        for(;it!=adj_list[i].children.end();++it){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

bool hasMachine(int father, int number){
    bool result = false;
    while(father != -2){
        if(adj_list[father].number > number)
            return true;
        father = adj_list[father].father;
    }
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
        n.number= -1;
        n.father = 0;
        adj_list.push_back(n);
    }

    for(int i=0;i<n-1;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj_list[x].neighbour.insert(y);
        adj_list[y].neighbour.insert(x);

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

    build();
    for(int i=0;i<adj_list.size();i++)
        countMachine(i);

    sort(edges.begin(),edges.end(),edge_cmp());


    int count = 0;
    long long total = 0;
    for(int i=0;i<edges.size() && count < k;i++){
        edge e = edges[i];
        int father = e.i;
        int child = e.j;
        order(father,child);
        adj_list[father].children.erase(child);
        int n2 = number(child); 
        if(hasMachine(father,n2)&& n2!=0){
            change(father,n2);
            count++;
            total+=e.weight;
            adj_list[child].father = -2;
        }
        else{
            adj_list[father].children.insert(child);
        }
    }

    cout<<total<<endl;

    return 0;
}
