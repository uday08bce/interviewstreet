#include <iostream>
#include <string>

using namespace std;

int n;
int q;
int last;
bool flag;
int a[100001];
int b[100001];
int m[100001];

void set(int *a, int pos,int value){
    a[pos] = value;
}

bool test(int *a, int pos){
    if(a[pos] == 1)
        return true;
    else
        return false;
}


void debug(){
    cout<<"debug info"<<endl;
    cout<<"a :";
    for(int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;

    cout<<"b :";
    for(int i=0;i<n;i++)
        cout<<b[i];
    cout<<endl;

    cout<<"c :";
    for(int i=0;i<=n;i++)
        cout<<m[i];
    cout<<endl;
}
void compute(int start){
    for(int i=start;i<n;i++){
        if( (a[i] & b[i]) == 1){
            if(flag){
                m[i] = 1;
            }
            else{
                m[i] = 0;
                flag = true; 
            }
        }
        else if( (a[i] | b[i]) == 1){
            if(flag){
                m[i] = 0;
            }
            else{
                m[i] = 1;
            }
        }
        else{
            if(flag)
                m[i] = 1;
            else
                m[i] = 0;
            flag = false;
        }
    }

    if(flag)
        m[n] = 1;
    else
        m[n] =0;
    last = n;
    //debug();
}

int main(){
    cin>>n>>q;

    string ss;
    cin>>ss;
    for(int i=0;i<n;i++){
        if(ss[i] == '1')
            a[i] =1;
        else
            a[i] = 0;
    }

    cin>>ss;
    for(int i=0;i<n;i++){
        if(ss[i] == '1')
            b[i] =1;
        else
            b[i] = 0;
    }

    flag = false;
    compute(0);

    //debug();
    string action;
    int pos;
    int value;
    while(q>0){
        cin>>action; 
        if(action == "set_a"){
            cin>>pos;
            cin>>value;
            if(last>pos)
                last = pos;
            a[pos] = value;

        }
        else if(action == "set_b"){
            cin>>pos;
            cin>>value;
            if(last > pos)
                last = pos;
            b[pos] = value;
        }
        else if(action == "get_c"){
            cin>>pos;
            if(pos < last)
                cout<<m[pos];
            else{
                compute(last);
                cout<<m[pos];
            }
        }
        q--;
    }
    cout<<endl;
    return 0;
}

