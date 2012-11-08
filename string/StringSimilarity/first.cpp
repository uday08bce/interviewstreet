#include <iostream>

using namespace std;


int similarity(const char *s1,int length1, const char *s2,int length2){
    int i=0;
    int j=0;
    int total = 0;
    for(;i<length1 && j<length2;i++,j++){
        if(s1[i] == s2[j])
            total++;
        else
            break;
    }
    return total;

}

int sum(string & s){
    int total = 0;
    for(int i=0;i<s.length();i++){
        total+=similarity(s.data(),s.length(),s.data()+i,s.length()-i);
    }
    return total;
}

int main(){
    int case_number;
    cin>>case_number;

    while(case_number>0){
        string ss;
        cin>>ss;
        cout<<sum(ss)<<endl;
        case_number--;
    }
    return 0;
}
