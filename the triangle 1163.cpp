#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

using namespace std;

int numbers[101];
int dp[101];

int main()
{
    int N,max=0;
    cin>>N;

    cin>>dp[0];

    for(int i=1;i<N;i++){

        for(int j=0;j<=i;j++){
            cin>>numbers[j];
        }
        numbers[0]=numbers[0]+dp[0];
        for(int k=1;k<i;k++){
            numbers[k]=(dp[k-1]+numbers[k]>dp[k]+numbers[k])?dp[k-1]+numbers[k]:dp[k]+numbers[k];
//            cout<<k<<" "<<dp[k]<<" "<<dp[k-1]<<" "<<numbers[k]<<endl;
        }

        numbers[i]=dp[i-1]+numbers[i];

        for(int l=0;l<=i;l++){
            dp[l]=numbers[l];
        }
    }

    for(int i=0;i<N;i++){
        max=(max>dp[i])?max:dp[i];
    }
    cout<<max<<endl;

    return 0;
}


