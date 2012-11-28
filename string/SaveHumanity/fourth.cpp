#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

void sunday(const string & s1, const string &s2, vector<int>& v){

    if(s2.length()>s1.length())
        return ;

    int start = 0;

    int middle = s2.length()/2;

    string first = s2.substr(0,middle); 
    string second = s2.substr(middle);


    while(start <= (s1.length() - s2.length())){

        int j =0;
        for(;j<first.length();j++){
            if(s1[start+j] != first[j])
                break;
        }

        if(j == first.length()){
            // found

            int diff = 0;
            for(int m=0;m<second.length();m++){
                if(s1[start+j+m] != second[m])
                    diff++;
                if(diff>1)
                    break;
            }
            if(diff<=1)
                v.push_back(start);
        }

        int next = start + first.length();

        // arrive end
        if(next >= s1.length())
            break;

        int k = 0;
        for(;k<first.length();k++){
            char c = first[first.length() - k - 1];
            if(c == s1[next])
                break;
        }

        // no s1[next] in s2, we move s2.length()
        if(k == first.length()){
            start += first.length();
        }
        else{
            start += k+1;
        }
    }


    return ;
}

void reverse_sunday(const string & s1, const string &s2, vector<int> & v){

    if(s2.length()>s1.length())
        return ;


    int middle = s2.length()/2;

    string first = s2.substr(0,middle); 
    string second = s2.substr(middle);

    int start = first.length();

    while(start <= s1.length()-1){

        int j =0;
        for(;j<second.length();j++){
            if(s1[start+j] != second[j])
                break;
        }

        if(j == second.length()){

            // found

            int diff = 0;
            for(int m=0;m<first.length();m++){
                if(s1[start-first.length()+m] != first[m])
                    diff++;
                if(diff>1)
                    break;
            }
            if(diff==1)
                v.push_back(start - first.length());
        }

        int next = start + second.length();

        // arrive end
        if(next >= s1.length())
            break;

        int k = 0;
        for(;k<second.length();k++){
            char c = second[second.length() - k - 1];
            if(c == s1[next])
                break;
        }

        // no s1[next] in s2, we move s2.length()
        if(k == second.length()){
            start += second.length();
        }
        else{
            start += k+1;
        }
    }


    return ;
}




int main(){

    int n;
    cin>>n;

    string s1, s2;
    while(n>0){
        cin>>s1;
        cin>>s2;

        if(s2.length() ==1){
            for(int i=0;i<s1.length();i++){
                cout<<i<<" ";
            }
        }
        else{
            vector<int> first;
            sunday(s1,s2,first);

            reverse_sunday(s1,s2,first);

            sort(first.begin(), first.end());
            copy(first.begin(),first.end(), ostream_iterator<int>(cout, " "));
            //copy(second.begin(),second.end(),ostream_iterator<int>(cout, " "));
        }
        cout<<endl;
        n--;
    }
    return 0;

}

