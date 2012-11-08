#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

bool isMatch(const string &s1, const string & s2, int pos){
    int diff =0;
    for(int i=0;i<s2.length();i++){
        if(s1[pos+i] != s2[i])
            diff++;
        if(diff>1)
            return false;
    }

    if(diff>1)
        return false;
    else
        return true;
}

vector<int> count(const string &s1, const string & s2){
    vector<int> result;
    if(s1.length()<s2.length())
        return result;

    string sorted = s2;
    sort(sorted.begin(),sorted.end());

    int same = 0;
    for(int i=0;i<s2.length();i++){
        if(binary_search(sorted.begin(),sorted.end(),s1[i]))
            same++;
    }

    if(same>=s2.length()-1){
        if(isMatch(s1,s2,0))
            result.push_back(0);
    }


    for(int i=1;i<=(s1.length() - s2.length());i++){
        if(binary_search(sorted.begin(),sorted.end(),s1[i-1]))
            same--;
        if(binary_search(sorted.begin(),sorted.end(),s1[i+s2.length() - 1]))
            same++;

        if(same >= s2.length()-1){
            if(isMatch(s1,s2,i))
                result.push_back(i);
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

        vector<int> v = count(s1,s2);
        if(v.size() == 0){
            cout<<endl;
        }
        else{
            copy(v.begin(),v.end(),ostream_iterator<int>(cout, " "));
            cout<<endl;
        }
    }
}
