#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <cassert>
using namespace std;

#define MAXVALUE 1000000


int main()
{
    int number,num;
    cin>>number;
    while(number-->0){
        cin>>num;

        int multiple=1;
        int dividend=5;
        int NumOfFive=0;
        while(num>=dividend){

//            cout<<pow(5,multiple)<<endl;
            NumOfFive+=num/dividend;

            multiple++;
            dividend=dividend*5;
        }
        cout<<NumOfFive<<endl;
    }
}


