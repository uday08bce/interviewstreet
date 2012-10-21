#include <iostream>

using namespace std;

int a[100001];
long long max_profit[100001];

int k;
int n;

long long profit(int start, int length){
    if(length<=0)
        return 0;

    if(start>=n)
        return 0;

    if(max_profit[start] != -1)
        return max_profit[start];

    long long temp = 0;
    long long m = profit(start+1,length-1);;
    long long accu= 0;
    for(int i=1;i<=k;i++){
        temp = profit(start+i+1,length-i-1); 
        accu += a[start+i-1];
        temp += accu;
        if(temp > m)
            m = temp;
    }


    max_profit[start] = m;
    return max_profit[start];
    
}

int main(){
    //cin>>n;
    //cin>>k;
    
    scanf("%d",&n);
    scanf("%d",&k);

    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
        max_profit[i] = -1;
    }


    max_profit[n-1] = a[n-1];
    for(int i=1;i<k;i++){
        max_profit[n-1-i] =  a[n-i-1] + max_profit[n-i];
    }

    printf("%lld\n",profit(0,n));
    //cout<<profit(0,n)<<endl;

    return 0;
}
