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

    for(int i=n-1;i>=0;i--){
        scanf("%d",&a[i]);
    }


    max_profit[0] = a[0];
    for(int i=1;i<k;i++){
        max_profit[i] = a[i] + max_profit[i-1];
    }

    for(int i=k;i<n;i++){
        long long temp = max_profit[i-1];
        long long accu = 0;
        for(int j=1;j<=k;j++){
            accu += a[i-j+1]; 
            if(temp < max_profit[i-j-1] + accu)
                temp = max_profit[i-j-1] + accu;
        }

        max_profit[i] = temp;
    }


    debug();
    cout<<max_profit[n-1]<<endl;

    return 0;
}

