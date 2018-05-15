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

#define MAXVALUE 1000000

bool isPrime[MAXVALUE];

void Sieve(){
    memset(isPrime,true, sizeof(bool)*MAXVALUE);

    for(int i=2;i*i<MAXVALUE;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAXVALUE;j+=i){
                isPrime[j]=false;
            }
        }
    }
}

int main()
{
    Sieve();
    int n;
    bool flag=false;
    while(cin>>n){
        if(n==0)
            break;
        flag=false;
        for(int i=3;i<n;i++){
            int j=n-i;
            if(i%2==1&&j%2==1&&isPrime[i]&&isPrime[j]){
                cout<<n<<" = "<<i<<" + "<<j<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
            cout<<"Goldbach's conjecture is wrong."<<endl;
    }
}


