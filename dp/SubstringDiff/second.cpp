#include <iostream>
#include <string>
#include <vector>
#include "limits.h"

using namespace std;

const int line_max = 1500;


int f[line_max][line_max];
int number[line_max][line_max];

string s1,s2;
int k;

int longest = INT_MIN;

int func(int i, int j){
    if(f[i][j] != -1)
        return f[i][j];

    if(i == s1.length()-1 || j == s2.length()-1){
        if(s1[i] == s2[j]){
            f[i][j] = 1;
            number[i][j] = 0;
        }
        else{
            if(k == 0)
                f[i][j] = 0;
            else{
                f[i][j] = 1;
                number[i][j] = 1;
            }
        }
        return f[i][j]; 
    }

    if(s1[i] == s2[j]){
        f[i][j] = func(i+1,j+1);
        number[i][j] = number[i+1][j+1];
        return f[i][j];
    }
    else{
        int temp = func(i+1,j+1); 
        
        if(number[i+1][j+1] < k){
            f[i][j] = temp+1;
            number[i][j] = number[i+1][j+1] + 1;
        }
        else{
            f[i][j] = f[i+1][j+1] - 1;
            number[i][j] = k;
        }
        return f[i][j]; 
    }

    return f[i][j];
}

int count(){
    for(int i=0;i<s1.length();i++){
        for(int j=0;j<s2.length();j++){
            int temp = func(i,j); 
            if(temp > longest)
                longest = temp;
        }
    }
    return longest;
}


void reset(){
    for(int i=0;i<line_max;i++){
        for(int j=0;j<line_max;j++)
            f[i][j] = -1;
    }
}

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){

        reset();
        cin>>k;
        cin>>s1;
        cin>>s2;

        cout<<count()<<endl;

    }

    return 0;
}
