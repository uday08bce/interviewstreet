#include <iostream>
#include "limits.h"

using namespace std;

int a[100000];
int f[100000];

int q[100000];
int main(){
    int n,k;
    cin>>n;
    cin>>k;

    long long total = 0;

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        total += a[i];
    }

    if(n == k){
        cout<<total<<endl;
        return 0;
    }

    int head, tail;
    head = 0;
    tail = -1;

    for(int i=0;i<=k;i++){
        f[i] = a[i];
        while(tail>=head && f[i] < f[q[tail]]){
            tail--;
        }
        q[++tail] = i;
    }

    for(int i=k+1;i<n;i++){
        while( (i-q[head])>(k+1))
            head++;

        f[i] = f[q[head]] + a[i];
        while(tail>head && f[i] < f[q[tail]]){
            tail--;
        }
        q[++tail]= i;
    }

    int min_value = INT_MAX;
    for(int i=0;i<=k&&(n-1-i)>=0;i++){
        if(min_value > f[n-1-i])
            min_value = f[n-1-i];
    }

    cout<<total - min_value<<endl;
    return 0;
}
