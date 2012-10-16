#include <iostream>
#include <stdlib.h>

using namespace std;


int compare(const void *p, const void *q){
    long long i = *((long long*)p);
    long long j = *((long long*)q);
    if(i<j)
        return -1;
    else if(i>j)
        return 1;
    else
        return 0;
}

int main(){
    int n;
    long long k;
    cin>>n;
    cin>>k;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];


    qsort(a,n,sizeof(long long), compare);
    int total = 0;

    for(int i=0;i<n;i++){
        long long l = a[i]+k;
        if(NULL!=bsearch((void *)&l,a,n,sizeof(long long),compare))
            total++;
    }

    cout<<total<<endl;                    
    
    return 0;
}
