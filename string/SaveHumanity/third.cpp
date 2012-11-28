#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;



// sunday
vector<int> sunday(const string &s1,const string & s2){

    vector<int> result;
    if(s2.length() > s1.length())
        return result;

    int start = 0;

    while(start <= s1.length() - s2.length()){

        int i = 0;
        for(; i<s2.length(); i++){
            if(s1[start+i] != s2[i])
                break;
        }

        if(i == s2.length()){
            result.push_back(start);
            start++;
        }

        else{
            int temp = start+s2.length();
            if(temp>=s1.length())
                break;

            int j = s2.length()-1;
            for(;j>=0;j--){
                if(s2[j] == s1[temp])
                    break;
            }

            if(j<0){
                start = temp;
            }
            else{
                start = start + s2.length()- j;
            }
        }

    }

    return result;

}


bool match(const string &s1, const string & s2){

    int diff = 0;
    for(int i=0;i<s2.length();i++){
        if(s1[i] != s2[i]){
            diff++;
        }

        if(diff > 1)
            return false;
    }

    return true;
}

vector<int> count(const string & s1, const string &s2,const vector<int> & vec, int prefix){

    vector<int> result;

    for(int i=0;i<vec.size();i++){
        if( (s1.length() - vec[i] - 1) < s2.length())
            break;
        string temp = s1.substr(vec[i] + prefix);
        if(match(temp,s2))
            result.push_back(vec[i]);
    }


    return result;
}

int main(){
    int n;
    cin>>n;

    string s1;
    string s2;

    for(int i=0;i<n;i++){
        cin>>s1;
        cin>>s2;

        string before;
        string after;

        before = s2.substr(0,s2.size()/2);
        after = s2.substr(s2.size()/2);

        vector<int> prefix = sunday(s1, before);
        vector<int> middle = count(s1, after, prefix, before.length());


        reverse(s1.begin(),s1.end());
        reverse(after.begin(),after.end());
        reverse(before.begin(),before.end());

        vector<int> reverse_prefix = sunday(s1, after);
        vector<int> reverse_middle = count(s1, before, reverse_prefix, after.length());


        //cout<<"reverse"<<endl;
        for(int i=0; i<reverse_middle.size();i++){
            int temp = reverse_middle[i] + s2.length() - 1;
            //cout<<s1.length() - temp - 1<<" ";
            middle.push_back(s1.length() - temp - 1);
        }
        //cout<<"reverse over"<<endl;



        sort(middle.begin(),middle.end());
        vector<int>::iterator it= unique(middle.begin(),middle.end());

        copy(middle.begin(),it,ostream_iterator<int>(cout, " "));
        cout<<endl;

    }
    return 0;
}
