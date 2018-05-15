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

#define MAXN 102
int sum[MAXN*101];
int stock[MAXN];

int main(){

    int n,x;
    while(true){
        cin>>n>>x;

        if(n==0&&x==0)
            break;

        double percent;
        memset(stock,0, sizeof(stock));
        memset(sum,0, sizeof(sum));
        for(int i=1;i<=n;i++){
            cin>>percent;
            stock[i]=int(percent*100+0.5);
        }
        sum[stock[x]]=1;

        for(int j=1;j<=n;j++){
            if(j==x)
                continue;

            for(int k=10000;k>=stock[j];k--){
                if(sum[k-stock[j]]==1)
                    sum[k]=1;
            }
        }

        int total=0;
        for(int i=5001;i<=10000;i++){
            if(sum[i]==1){
                total=i;
                break;
            }
        }

        double ans=100.0*((double)stock[x])/((double)total);
        printf("%.2f\n",ans);
    }

}