#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f
int Village[303];
int cost[303][303];
int dp[303][303];

int main()
{
    int NumOfVillage,NumOfOffice;
    cin>>NumOfVillage>>NumOfOffice;

    Village[0]=0;
    for(int i=1;i<=NumOfVillage;i++)
        cin>>Village[i];

    //compute cost
    for(int i=1;i<=NumOfVillage;i++){
        for(int j=i;j<=NumOfVillage;j++){
            int middle=(i+j)/2;
            cost[i][j]=0;
            for(int k=i;k<=j;k++){
                cost[i][j]+=abs(Village[k]-Village[middle]);
            }
        }
    }

    memset(dp,INF, sizeof(dp));
    dp[0][0]=0;

    for (int i = 1; i <= NumOfOffice; i++) {
        for (int j = i; j <= NumOfVillage; j++) {
            for (int k = 0; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i-1][k] + cost[k+1][j]);
        }
    }

    cout<<dp[NumOfOffice][NumOfVillage]<<endl;

    return 0;
}

