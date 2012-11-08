#include <iostream>
#include <algorithm>

using namespace std;

int a[100000];


double getMedian(int total){
    int index = total/2;
    if(total %2 ==0){
        return (double)((double)a[index]+a[index-1])/2;
    }
    else{
        return a[index];
    }
}

int main(){
    int number;
    cin>>number;

    char action;
    int item;
    int total = 0;

    while(number>0){
        cin>>action;
        cin>>item;

        if(action == 'a'){
            a[total++]=item;
            sort(a,a+total);
            cout<<getMedian(total)<<endl;
        }

        else if(action == 'r'){
            if(total == 0){
                cout<<"Wrong!"<<endl;
            }
            else if(total == 1){
                total--;
                cout<<"Wrong!"<<endl;
            }
            else{
                int * p =lower_bound(a,a+total,item);         
                if(*p == item){
                    total--;
                    *p = a[total]; 
                    sort(a,a+total);
                    cout<<getMedian(total)<<endl;
                }
                else
                    cout<<"Wrong!"<<endl;

            }
        }

        number--;
    }
    return 0;
}
