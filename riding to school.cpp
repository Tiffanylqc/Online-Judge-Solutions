#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cmath>
using namespace std;
#define MAXN 10000

int main()
{
    int NumOfRider,maxSpeed,time,speed,startTime,minTime;
    while(cin>>NumOfRider){
        if(NumOfRider==0){
            break;
        }

        maxSpeed=0;
        minTime=0x7fffffff;
        while(NumOfRider-->0){
            cin>>speed>>startTime;

            if(startTime>=0){
                time=ceil(4.5/speed*3600.0+startTime);
                if(time<minTime)
                    minTime=time;
            }

        }

        cout<<minTime<<endl;

    }

}


