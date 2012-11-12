#include <iostream>
#include <string>
#include <vector>
#include "limits.h"

using namespace std;

const int line_max = 1500;


string s1,s2;
int k;

int longest = INT_MIN;

int count(){
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            vector<int> v;
            int t =0;
            while(i+t < s1.length() && j+t<s2.length()){
                if(s1[i+t] != s2[j+t]){
                    v.push_back(i+t);
                }
                t++;
            }
            for(int i=k;i<v.size();i++){
                //cout<<v[i]<<" ";
                int temp = v[i] - v[i-k];
                if(temp > longest)
                    longest = temp;
            }
            //cout<<endl;
        }
    }
    return longest;
}


int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){

        cin>>k;
        cin>>s1;
        cin>>s2;

        cout<<count()<<endl;

    }

    return 0;
}
