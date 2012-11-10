#include <iostream>
#include <vector>
#include "limits.h" 
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;

    int temp;
    int min = INT_MAX;
    int min_index = -1;
    vector<int> v;
    vector<int> r;

    for(int i=0;i<n;i++){
       cin >> temp;
       v.push_back(temp);
       r.push_back(1);
       if(temp < min)
           min = temp;
       min_index = v.size()-1;
    }
    

    int total = 1;
    int current = 1;
    int pre = v[min_index];
    for(int i=min_index+1; i<v.size(); i++){
       if(v[i] <= pre){
           current = 1;
       }
       else{
           current++;
       }
       pre = v[i];
       r[i] = current;
       total += current;
    }

    current =1 ;
    pre = min;
    for(int i = min_index-1;i>=0;i--){
        if(v[i] <= pre)
            current = 1;
        else
            current++;
        pre = v[i];
        r[i] = current;
        total+=current;
    }
    
   
    cout<<total<<endl;

//    copy(r.begin(),r.end(),ostream_iterator<int>(cout,"\n"));
    return 0;
}
