#include <iostream>
#include <vector>

using namespace std;


int a[101][101];

struct node{
    int value;
    int number;  // number of children include itself
    vector<node *> children;
};

int n,m;
int g_total = 0;

void buildNode(int value, node * parent){
    for(int i=1;i<=n;i++){
        if(a[value][i] == 1){
            a[value][i] = 0;
            a[i][value] = 0;
            node * child = new node;
            child->value = i;
            child->number= 0;
            parent->children.push_back(child);
            buildNode(i, child);
        }
    }
}

node * build(){
    node * root = new node;
    root->value = 1;
    root->number=0;

    buildNode(1, root);

    return root;

}


int compute(node * root){
    if(root->number==0){
        int total = 0;
        for(int i=0;i < root->children.size(); i++){
            total += compute(root->children[i]);
        }

        root->number = total +1;
    }
    if(root->number % 2  ==0)
        g_total++;
    return root->number;

}

void print(node * root){
    cout<<root->value<< " " << root->number <<endl;
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}

int main(){
    cin>>n>>m;

    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    node * root = build();
    compute(root);
    //print(root);

    cout<<--g_total<<endl;
    return 0;
}
