#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include <vector>
#include <cmath>

using namespace std;



int main()
{

    int n,m,inversion,invertSeq;
    while(cin>>n>>m){
        if(n==-1&&m==-1)
            break;

        int i;
        int invertSeq=1;
        while(invertSeq*(invertSeq-1)/2<m)
            invertSeq++;

        int first=n-(invertSeq*(invertSeq-1)/2-m);

        for(int j=1;j<=n-invertSeq;j++){
            cout<<j<<" ";
        }

        cout<<first<<" ";

        for(int j=n;j>n-invertSeq;j--){
            if(j!=first)
                cout<<j<<" ";
        }
        cout<<endl;
    }
}


