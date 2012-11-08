#include <iostream>

using namespace std;

int a[100000];



char ranact(){
    if( random()%2 ==0)
        return 'a';
    else
        return 'r';
}


int rannum(int number){
    return random()%number;
}

int main(){
    int number;
    cin>>number;

    srandom(time(NULL));

    cout<<number<<endl;
    for(int i=0;i<number;i++){
        cout<<ranact()<<" "<<rannum(number)<<endl;
    }
    
    return 0;
}
