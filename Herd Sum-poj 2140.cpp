#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 10000000

int main()
{
    int N,left=1,right=1,sum=1;
    cin>>N;

    int count=0;
    while(left<=right&&right<=N){
        if(N==sum){
            count++;
            sum-=left;
            left++;
        }
        else if(N>sum){
            right++;
            sum+=right;
        }
        else if(N<sum){
            sum-=left;
            left++;
        }
    }
    cout<<count<<endl;

}


