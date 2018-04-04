#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <cstdio>
using namespace std;

#define MAX_N 251
int m,n,c;
map<string,int> nameMap;
vector<int> v[MAX_N];
bool root[MAX_N];
int cost[MAX_N];
string subName;
char str[1001];
const int inf=0x3fffffff;
int dp[MAX_N][MAX_N];

int dfs(int root){
    for(int i=1;i<=n;i++)
        dp[root][i]=inf;
    dp[root][0]=0;

    int child=1;
    for(int i=0;i<v[root].size();i++){
        child+=dfs(v[root][i]);
        int to=v[root][i];
        for(int j=n;j>=0;j--){
            for(int k=0;k<=j;k++){
                dp[root][j]=min(dp[root][j],dp[root][j-k]+dp[to][k]);
            }
        }
    }
    dp[root][child]=min(dp[root][child],cost[root]);
    return child;
}

int main(){
    while(gets(str)&&str[0]!='#'){
        sscanf(str,"%d %d",&n,&m);

        //initialize
        nameMap.clear();
        for(int i=0;i<=n;i++)
            v[i].clear();
        memset(root,true, sizeof(root));

        int id=1;
        for(int i=0;i<n;i++){
            cin>>str>>c;
            if(nameMap.find(str)==nameMap.end())
                nameMap[str]=id++;

            int index=nameMap[str];
            cost[index]=c;

            gets(str);
            stringstream ss(str);
            while(ss>>subName){
                if(nameMap.find(subName)==nameMap.end())
                    nameMap[subName]=id++;
                int to=nameMap[subName];
                root[to]=false;
                v[index].push_back(to);
            }
        }

        for(int i=1;i<=n;i++){
            if(root[i])
                v[0].push_back(i);
        }
        cost[0]=inf;

        dfs(0);
        int result=inf;
        for(int i=n;i>=m;i--)
            result=min(result,dp[0][i]);
        cout<<result<<endl;
    }
}
