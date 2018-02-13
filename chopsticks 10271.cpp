#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int chopSticks[5020];
int dp[5020][1020];
int main(){
    int NumOfCases,K,N;
    cin>>NumOfCases;

    while(NumOfCases-->0){
        cin>>K>>N;
        K=K+8;
        for(int i=N;i>=1;i--)
            cin>>chopSticks[i];
        memset(dp, 0x3f, sizeof dp);
        dp[0][0]=0;

        for(int i=1;i<=N;i++){
            for(int j=0;j*3<=i;j++) {
                dp[i][j]=dp[i-1][j];
                if(j-1>=0&&i-2>=0)
                    dp[i][j]=min(dp[i][j],dp[i-2][j-1]+(chopSticks[i-1]-chopSticks[i])*(chopSticks[i-1]-chopSticks[i]));
            }
        }

        cout<<dp[N][K]<<endl;
    }
}
