#include <iostream>

using namespace std;

int main(){
    int n;
    long long k;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
        {
            if(abs(a[i]-a[j]) == k)
                    total++;
        }
    }

    cout<<total<<endl;                    
    
    return 0;
}
