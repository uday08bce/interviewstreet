#include <iostream>
#include "stdio.h"
#include "limits.h"

using namespace std;


int a[100000];
int q[100000];
int value[100000];

int head = 0;
int tail = -1;

int main(){
    int n,k;
    cin>>n;
    cin>>k;

    long long total = 0;
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
        total += a[i];
    }

    for(int i=0;i<k+1;i++){

        value[i] = a[i];
        q[++tail] = i;
    }

    for(int i=k+1;i<n;i++){
        while( (i - q[head] ) >=k)
            head++;
        value[i] = a[i] + value[q[head]];

        while( tail >= head && value[q[tail]] > value[i])
            tail--;
        q[++tail] = i;
    }

    long long min = LONG_MAX;
    for(int i=0;i<k+1;i++){
        if(value[n-i-1] < min)
            min = value[n-i-1];
    }

    cout<<total - min <<endl;
    return 0;
}
