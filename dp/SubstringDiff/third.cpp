#include <iostream>
#include <string>
#include <deque>

using namespace std;

int k;
int longest;
string s1,s2;


int count(){
    for(int i=s1.length()-1;i>=0;i--){
        int t = 0;
        deque<int> q;
        int total=0;

        while(1){
            int m=i-t;
            int n = s2.length()-1-t;

            if(m <0 || n <0)
                break;

            if(s1[m] != s2[n]){
                //cout<<"queue size " << q.size()<<endl;
                if(q.size() < k){
                    q.push_back(m);
                    total++;
                }
                else{
                    //cout<<"m= "<<m<< " front = "<< q.front()<<endl;
                    total = q.front() - m ;
                    q.pop_front();
                    q.push_back(m);
                }
            }
            else
                total++;

            if(total>longest)
                longest = total;

            //cout<<"total = " << total<<endl;
            t++;
        }
        //cout<<"i =" <<i  <<" l= " << longest<<endl;
    }

    for(int i=s2.length()-1;i>=0;i--){
        int t =0;
        int total = 0;
        deque<int> q;
        while(1){
            int m = i-t; // s2
            int n = s1.length()-t-1; //s1
            if(m<0 || n <0)
                break;
            if(s2[m] != s1[n]){
                if(q.size() < k){
                    q.push_back(m);
                    total++;
                }
                else{
                    total = q.front() - m;
                    q.pop_front();
                    q.push_back(m);
                }
            }
            else
                total++;


            if(total>longest)
                longest = total;
            t++;
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

        longest = INT_MIN;
        cout<<count()<<endl;
    }
    return 0;
}

