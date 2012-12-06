#include <iostream>
#include <vector>
#include <set>
#include <deque>

using namespace std;


struct node{
    vector<int> next;
    bool visited_1;
    bool visited_2;
    int reachable; // 0 means not compute, 1 means can reach , -1 means can`t reach
    int distance;  // -2 means not compute, -1 means infinite 
};

vector<node> nodes;
deque<int> q;

bool isReachable(int i, int j){
    if(i == j)
        return true;

    if(nodes[i].visited_2)
        return false;

    if(nodes[i].reachable == 1)
        return true;
    else if(nodes[i].reachable == -1)
        return false;


    nodes[i].visited_2 = true;
    bool anyone = false;
    vector<int>::iterator it = nodes[i].next.begin();
    for(;it!=nodes[i].next.end();++it){
        if(isReachable((*it),j)){
            anyone = true;
            break;
        }
    }

    nodes[i].visited_2 = false; 
    if(anyone){
        nodes[i].reachable=1;
        return true;
    }
    else{
        nodes[i].reachable=-1;
        return false;
    }

}

int count(int pos, int dest){
    if(nodes[pos].distance >=0)
        return nodes[pos].distance;

    if(nodes[pos].visited_1){
        deque<int>::reverse_iterator it = q.rbegin();
        for(;it!=q.rend();++it){
            if(*it == pos)
                break;
            if(isReachable(*it,dest))
                return -1;
        }
        return 0;
    }

    nodes[pos].visited_1 = true;
    q.push_back(pos);

    int result = 0;
    if(pos == dest)
        result = 1;
    vector<int>::iterator it = nodes[pos].next.begin();
    for(;it!=nodes[pos].next.end();++it){
        int temp = count(*it,dest);
        if(temp == -1){
            result = -1;
            break;
        }
        result = (result+temp)%1000000000;
    }
    q.pop_back();

    nodes[pos].distance = result;

    nodes[pos].visited_1 = false;
    return result;
    
}

int main(){
    int n,m;
    cin>>n>>m;

    nodes.push_back(node());

    for(int i=0;i<n;i++){
        node n;
        n.reachable = 0;
        n.visited_1 = false;
        n.visited_2 = false;
        n.distance = -2;
        nodes.push_back(n);
    } 

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        nodes[x].next.push_back(y);
    }

    int result = count(1,n);
    if(result == -1)
        cout<<"INFINITE PATHS"<<endl;
    else
        cout<<result<<endl;
    return 0;
}
