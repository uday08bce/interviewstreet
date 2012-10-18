#include <iostream>
#include <algorithm>

using namespace std;

int a[1000000];

int main(){
    int n,k;
    cin>>n;
    cin>>k;

    for(int i=0;i<n;i++)
        cin>>a[i];

    sort(a,a+n);

    int result = 0;
    for(int i=0;i<n;i++){
        result+=a[i]*(i/k+1);
    }
    cout<<result<<endl;
    return 0;
}
