#include<iostream>
#include <string.h>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

using namespace std;




int main(){

    int NumOfCases;
    double a,b,S;
    cin>>NumOfCases;

    double prob;
    while(NumOfCases-->0){

        cin>>a>>b>>S;


        double x1=S/b;
        if(S==0){
            prob=1.0;
        }
        else if(x1>=a){
            prob=0.0;
        }

        else{
            double S1=S*log(a/x1);
            double bigS=a*b-S1-S;
            prob=bigS/(a*b);
        }
        printf("%.6f",prob*100);
        printf("%%\n");

    }

}
