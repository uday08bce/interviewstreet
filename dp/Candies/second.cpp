#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include "limit.h"

using namespace std;

vector<int> a;
vector<int> f;

int n;

void count(int i){
    if(f[i] != -1)
        return;

    int left, right;

    if(i == 0)
        left = INT_MAX;
    else
        left = a[i-1];

    if(i == n - 1)
        right = INT_MAX;
    else
        right = a[i+1];


    if(left >= a[i] && right >= a[i])
    {
        f[i] = 1;
    }
    else if(left >= a[i] && right < a[i]){
        count(i+1);
        int temp = f[i+1];
        f[i] = temp +1;
    }
    else if(left < a[i] && right >= a[i]){
        count(i-1);
        int temp = f[i-1];
        f[i] = temp +1;
    }
    else{
        count(i-1);
        count(i+1);

        int max = f[i-1] > f[i+1] ? f[i-1] : f[i+1];
        f[i] = max + 1;
    }
    return ;
}

int main(){
    cin>>n;


    for(int i=0; i<n;i++){
        int temp;
        cin>>temp;

        a.push_back(temp);
        f.push_back(-1);
    }

    for(int i=0; i<n; i++){
        count(i);
    }

    int total = 0;
    for(int i=0; i<n; i++)
        total += f[i];


    cout<<total<<endl;
    return 0;
}
