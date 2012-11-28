#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include "limits.h"

using namespace std;

vector<int> vec;

int max_number = INT_MIN;

void min(){
    int min = INT_MAX;
    int a ;
    for(int i=0;i<vec.size()-1;i++){
        a = vec[i] ^ vec[i+1];
        if(a<min)
            min = a;
    }

    if(vec.size()>=2){
        a = vec[vec.size()-1] ^ vec[0];
        if(a<min)
            min = a ;
    } 

    if(min > max_number)
        max_number = min;

}

int count(){
    int i = 1;
    int index =0 ; 
    while(max_number >= i){
        i = i*2;
        index++;
    }
    return index-1;

}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){

        int temp;
        cin>>temp;
        vec.push_back(temp);
        
    }

    sort(vec.begin(), vec.end());
    min();
    while(next_permutation(vec.begin(), vec.end())){
        copy(vec.begin(),vec.end(), ostream_iterator<int>(cout, " "));
        cout<<endl;
        min();
    }

    cout<<count()<<endl;
    return 0;
}
