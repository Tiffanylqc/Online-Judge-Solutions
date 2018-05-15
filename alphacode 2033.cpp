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


int main()
{
    string s;


    while(true){
        cin>>s;
        if(s.size()==1&&s[0]=='0')
            break;
        long dp[s.size()];
        memset(dp,0, sizeof(dp));
        dp[0]=1;

        if(10*(s[0]-'0')+(s[1]-'0')<=26&&s[1]!='0')
            dp[1]=2;
        else
            dp[1]=1;

        for(int i=2;i<s.size();i++){
            char prev=s[i-1];
            char now=s[i];
            if(now=='0')
                dp[i]=dp[i-2];
            else if(prev!='0'&&10*(prev-'0')+(now-'0')<=26)
                dp[i]=dp[i-2]+dp[i-1];
            else
                dp[i]=dp[i-1];
//            cout<<dp[i]<<endl;
        }
        cout<<dp[s.size()-1]<<endl;
    }



    return 0;
}


