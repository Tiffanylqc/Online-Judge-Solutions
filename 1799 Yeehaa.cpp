#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;

#define MAXN 110


int main()
{
    int NumOfCase;
    cin>>NumOfCase;

    double R,r;
    int n;
    for(int i=1;i<=NumOfCase;i++){
        cin>>R>>n;

        cout<<"Scenario #"<<i<<":"<<endl;

        r=R/(1+1/sin(3.1415926/n));

        printf("%.3f\n\n",r);
    }
}


