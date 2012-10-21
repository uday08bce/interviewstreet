#include <iostream>

using namespace std;

int a[100001];
long long max_profit[100001];

int k;
int n;


void debug(){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++)
        cout<<max_profit[i]<<" ";
    cout<<endl;
}

int main(){
    cin>>n;
    cin>>k;

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }


    long long total = 0;
    int pos = 0;
    int min_index = 0;
    int point = 0;
    while(pos<n){
        if( (pos - point) < k){
            if(a[pos]<=a[min_index]){
                min_index = pos;
            }
            pos++;
        }
        else{
            if(a[pos] < a[min_index])
                min_index = pos;
            a[min_index] = 0;
            min_index++;
            point = min_index;
            pos = min_index;
        }
    }
    /*
    if( (pos - point) > k)
        a[min_index]=0;
        */

    for(int i=0;i<n;i++)
        total+=a[i];

    cout<<total<<endl;

    return 0;
}

