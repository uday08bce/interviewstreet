#include <string>
#include <iostream>
#include "limits.h"

using namespace std;

int k;

string s1;
string s2;

int count(){
    int longest = INT_MIN;
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            int t=1;
            int total=0;
            while(1){
                if(i+t-1<s1.length() && j+t-1<s2.length()){
                    if(s1[i+t-1] != s2[j+t-1]){
                        total++;
                        if(total>k){
                            break;
                        }
                    }
                }
                else{
                    break;
                }
                t++;
            }
            t--;
            if(t > longest)
            {
                longest = t;
                //cout<<"i = "<<i << " j= " <<j << " t= " << longest<< endl;
            }
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
