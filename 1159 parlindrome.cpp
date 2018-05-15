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

short dp[5001][5001];
char s[5010];
int main()
{
    int length;
    cin>>length;

    char c;
    for(int i=0;i<length;i++){
        cin>>c;
        s[i]=c;
    }

    for(int l=0;l<length;l++){
        for(int i=0;i+l<length;i++){
            int start=i;
            int end=i+l;
            if(s[start]==s[end])
                dp[start][end]=dp[start+1][end-1];
            else
                dp[start][end]=min(dp[start+1][end],dp[start][end-1])+1;

        }
    }

    cout<<dp[0][length-1]<<endl;
}

