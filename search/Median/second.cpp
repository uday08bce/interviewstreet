#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];


double getMedian(int total){
    int index = total/2;
    if(total % 2 ==0){
        return (double)a[index]+a[index-1]/2;
    }
    else
        return a[index];
}


int main(){
    int total = 0; 
    int number;

    char act;
    int item;

    cin>>number;
    while(number>0){
        cin>>act;
        cin>>item;


        if(act == 'a'){
            int i = total-1;
            for(;i>=0;i--){
                if(a[i]>item){
                    a[i+1] = a[i];
                }
                else{
                    break;
                }
            }
            a[i+1] = item;
            total++;
            printf("%.12g\n",getMedian(total));
        }
        else if(act == 'r'){
            if(total == 0){
                cout<<"Wrong!"<<endl;
            }
            else{
                int *p = lower_bound(a,a+total, item); 
                if(*p == item){
                    int index = p-a;
                    for(int i=index;i<total-1;i++)
                        a[i] = a[i+1];
                    total--;
                    if(total == 0){
                        cout<<"Wrong!"<<endl;
                    }
                    else
                    {
                        printf("%.12g\n",getMedian(total));
                    }
                }
                else{
                    cout<<"Wrong!"<<endl;
                }
            }


        }

        number--;
    }
    return 0;
}

