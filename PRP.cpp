#include <bits/stdc++.h>
using namespace std;

struct BG{
    int percentage;
    double prob_positive;
        double prob_negative;

   
};
// General Trend of BGs : (Can refer this for nicer observations)
// World Population : 7,795,000,000 (7.8 Billion)
// O = 37;
// B = 33;
// A = 22
// AB = 8
// RH+ = 85
// RH- = 15
int main(void){
    int A,B,AB,O;
    struct BG Blood[4];
 string c[8] = {"A+ ","A- ","AB+","AB-","B+ ","B- ","O+ ","O- "};
    int pop;
    string s;
    int rh_positive;
    cout<<"Enter percentage of population in A Blood Group :" ; 
    cin>>A;
    Blood[0].percentage = A;
    cout<<"Enter percentage of population in AB Blood Group :" ; 
    cin>>AB;
    Blood[1].percentage = AB;
    cout<<"Enter percentage of population in B Blood Group :" ; 
    cin>>B;
    Blood[2].percentage = B;

    cout<<"Enter percentage of population in O Blood Group :" ; 
    cin>>O;
    Blood[3].percentage = O;
    cout<<"Enter RH+ value in % :";

    cin>>rh_positive;
    for(int i = 0; i<4;i++){
        Blood[i].prob_positive = (double)(rh_positive*Blood[i].percentage)/10000;
                Blood[i].prob_negative = (double)((100 - rh_positive)*Blood[i].percentage)/10000;

    }
    cout<<"Enter the blood group probability you want to check : ";
    cin>>s;
    cout<<"The population: ";
    cin>>pop;
    cout<<"The population with"<<" "<<s<<" "<<"blood group type is :"<<endl;
    if(s[1] == 'B'){
        if(s[2] == '+'){
            cout<<(int)(Blood[1].prob_positive*pop);
        }
         if(s[2] == '-'){
            cout<<(int)(Blood[1].prob_negative*pop);
        }
    }
    if(s[0] == 'B'){
         if(s[1] == '+'){
            cout<<(int)(Blood[2].prob_positive*pop);
        }
         if(s[1] == '-'){
            cout<<(int)(Blood[2].prob_negative*pop);
        }
    }
    if(s[0] == 'A'){
         if(s[1] == '+'){
            cout<<(int)(Blood[0].prob_positive*pop);
        }
         if(s[1] == '-'){
            cout<<(int)(Blood[0].prob_negative*pop);
        }
    }
     if(s[0] == 'O'){
         if(s[1] == '+'){
            cout<<(int)(Blood[3].prob_positive*pop);
        }
         if(s[1] == '-'){
            cout<<(int)(Blood[3].prob_negative*pop);
        }
    }
    cout<<endl;
    cout<<"Here goes our graphical plot : "<<endl;
    for(int i = 0; i< 8; i=i+2){
        cout<<c[i]<<" ";
        for(int j = 0; j <100*Blood[i/2].prob_positive;j++){
            cout<<"=";
        }
        cout<<endl;
        cout<<c[i+1]<<" ";
        for(int k = 0 ; k < 100*Blood[i/2].prob_negative;k++){
            cout<<"=";
        }
        cout<<endl;
    }
    }