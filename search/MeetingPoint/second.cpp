#include <iostream>
#include "limits.h"
#include "stdlib.h"

using namespace std;

struct position{
    long long x;
    long long y;
};

long long dist(const position & p1,const position &p2 ){
    long long w = abs(p1.x-p2.x); 
    long long h = abs(p1.y-p2.y);
    if(w>h)
        return w;
    else
        return h;
}


int compare_x(const void *a,const  void *b){
    position *p1 = (position *)a;  
    position *p2 = (position *)b;
    if(p1->x < p2->x)
    {
        return -1;
    }
    else if(p1->x > p2->x){
        return 1;
    }
    else{
        if(p1->y == p2->y)
            return 0;
        if(p1->y<p2->y)
            return -1;
        else
            return 1;
    }
}

long long sum(position *a, int length, int index){
    long long result = 0;
    for(int i=0;i<length;i++)
        result+=dist(a[i],a[index]);

    return result;
                
}

int main(){
    int number;
    cin>>number;

    position * a = new position[number];
    for(int i=0;i<number;i++)
    {
        cin>>a[i].x;
        cin>>a[i].y;
    }

    qsort(a,number,sizeof(position),compare_x);

    long long min = LONG_MAX; 

    if(number%2 ==0){
        int index = number/2;

        long long distance = 0;

        distance = sum(a,number,index);
        if(distance < min)
            min = distance;

    }
    else{
        int index = number/2;
        long long distance=0;

        distance = sum(a,number,index);
        if(distance < min)
            min = distance;

    }

    cout<<min<<endl;
    return 0;
}
