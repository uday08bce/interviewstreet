#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> similar(const string & s1, const string & s2){
    vector<int> result;
    if(s2.length()>s1.length())
        return result;

    for(int i = 0;i<=(s1.length() - s2.length());i++){
        int match = 0;
        for(int j = 0;j<s2.length();j++){
            if(s2[j] != s1[i+j]){
                match ++;
            }
            if(match > 1)
                break;
        }

        if(match <= 1)
            result.push_back(i);
        if(match == s2.length() && i+1<=(s1.length() - s2.length())){
            result.push_back(i+1);
            i++;
        }

    }

    return result;
}


int main(){
    int n;
    string s1,s2;
    string blank;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1;
        cin>>s2;
        
        vector<int> v = similar(s1,s2);
        if(v.size() == 0){
            cout<<endl;
        }
        else{
            copy(v.begin(),v.end(),ostream_iterator<int>(cout, " "));
            cout<<endl;
        }
    }
}
