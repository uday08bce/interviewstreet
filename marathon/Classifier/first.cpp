#include <vector>
#include <string>
#include <iostream>

using namespace std;

int trains ;
int features;

int numbers;

struct sample{
    vector<double> feature;
};

vector<double> positive;
vector<double> negative;

void init(int features){
    for(int i=0; i<features; i++)
    {
        positive.push_back(0);
        negative.push_back(0);
    }
}

void readSample(){
    string id;
    string score;
    cin>>id>>score;
    
    int num;
    char c;
    double feature = 0;
    if(score == "+1"){
        for(int i=0;i<features;i++){
            cin>>num>>c>>feature;
            positive[i] += feature; 
        }
    }
    else{
        for(int i=0;i<features;i++){
            cin>>num>>c>>feature;
            negative[i] += feature; 
        }
    }
}

void train(){
    for(int i=0;i<features;i++){
        positive[i] = positive[i] / trains;
        negative[i] = negative[i] / trains;
    }
}

void printTrain(){
    cout<<"positive"<<endl;
    for(int i=0;i<features;i++){
        cout<<positive[i]<<" ";
    }
    cout<<endl;

    cout<<"negative"<<endl;
    for(int i=0;i<features;i++){
        cout<<negative[i]<<" ";
    }
    cout<<endl;
}

bool classifier(vector<double> sample){
    double pos = 0;
    double neg = 0;
    for(int i=0;i<features;i++){
        pos += (sample[i] - positive[i]) * (sample[i] - positive[i]);
        neg += (sample[i] - negative[i]) * (sample[i] - negative[i]);
    }

    cout<<"pos "<<pos<<" neg "<<neg<<endl;
    if(pos >= neg){
        return true;
    }
    else
    {
        return false;
    }
}

int main(){

    cin>>trains>>features;

    init(features);

    string ss;
    for(int i=0; i<trains; i++){
        readSample();
    }

    train();
    //printTrain();
    cin>>numbers;

    string id ;
    string feature;
    for(int i=0;i<numbers;i++){
        cin>>id;
        vector<double> sample;

        int d;
        char c;
        double score;
        for(int j=0;j<features;j++){
            cin>>d>>c>>score;
            sample.push_back(score);
        }

        if(classifier(sample))
            cout<<id+" +1"<<endl;
        else
            cout<<id+" -1"<<endl;

    }

    return 0;
}
