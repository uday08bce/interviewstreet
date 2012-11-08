#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;


int main(){
    double i;
    while(1){
        cin>>i;
        /*
        int k = (int)i;
        if( (i - k)>0){
            printf("%g\n",i);
        }
        else{
            printf("%d\n",k);
        }
        */
        printf("%.20g\n",i);


    }
    return 0;
}
