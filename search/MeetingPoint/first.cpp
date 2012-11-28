#include <iostream>
#include "limits.h"

using namespace std;

long long distance(long long x1, long long y1, long long x2, long long y2){
    long long w = abs(x1-x2); 
    long long h = abs(y1-y2);
    if(w>h)
        return w;
    else
        return h;
}


struct position{
    long long x;
    long long y;
};

int main(){
    int number;
    cin>>number;

    position * a = new position[number];
    for(int i=0;i<number;i++)
    {
        cin>>a[i].x;
        cin>>a[i].y;
    }

    long long min = INT_MAX; 
    for(int i=0;i<number;i++){
        int temp = 0;
        for(int j=0;j<number;j++){
            if(i == j)
                continue;
            long long dist = distance(a[i].x,a[i].y,a[j].x,a[j].y);
            temp+=dist;
        }
        if(temp < min)
            min = temp;
    }

    cout<<min<<endl;
    return 0;
}
