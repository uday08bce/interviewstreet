#include <vector>
#include <string>
#include <iostream>

using namespace std;
 
char a[200][200]; //chess board
int number[200][200]; // posible


int n,m,s;

void loadboard(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
}


void print(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

void computeOne(int n, int i, int j, int s){
    if(number[i][j] != -1)
        return ;

    if(a[i][j] == 'P'){
        number[i][j] = 0;
        return;
    }

    int total= 0;

    //cout<<"==== "<<i <<" "<<j<<" ===="<<endl;
    //right
    for(int step = 0; step<=s;step++){
        for(int y_step = 0; y_step <= s-step; y_step++){
            int x = i+step;
            if(x>n-1)
                continue;

            int y = j+y_step;
            if(y>n-1)
                continue;
            if(a[x][y] != 'P'){
                //cout<<"x = "<<x <<" y= "<<y<<endl;
                total++;
            }

            int y2= j - y_step;
            if(y2 == y)
                continue;
            if(y2<0)
                continue;
            if(a[x][y2] != 'P'){
                //cout<<"x = "<<x <<" y= "<<y<<endl;
                total++;
            }
        }
    }
    total--;

    /*
    //left
    for(int step = -s; step <= -1;step++){
        for(int y_step = 0; y_step <= s+step; y_step++){
            int x = i+step;
            if(x<0)
                continue;

            int y = j+y_step;
            if(y>n-1)
                continue;
            if(a[x][y] != 'P')
                total++;

            int y2= j - y_step;
            if(y == y2)
                continue;
            if(y2<0)
                continue;
            if(a[x][y2] != 'P')
                total++;
        }
 
    }

    */
    number[i][j] = total;
    return;
}

void compute(int n, int s){
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++)
           computeOne(n,i,j,s);
   }
}


void printNumber(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<number[i][j]<<" ";
        cout<<endl;
    }
}

void reset(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            number[i][j] = -1;
    }
}

int main(){

    int t ;
    cin>>t;

    
    for(int i=0;i<t;i++){
        cin>>n>>m>>s;
        reset(n);
        loadboard(n);
        compute(n,s);
        //print(n);
        printNumber(n);
    }

    return 0;
}
