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
long long Strips[MAXN][MAXN];
long long row[MAXN];

int main(){

    int NumOfCases,N,M,maxarea,area,sum,first,cost;
    long long K;

    cin>>NumOfCases;

    for(int casenum=1;casenum<=NumOfCases;casenum++){
        cin>>N>>M>>K;

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>Strips[i][j];
            }
        }
        maxarea=-1;
        area=0;
        cost=0;

        for(int i=0;i<N;i++){
            memset(row,0, sizeof(row));
            for(int j=i;j<N;j++){
                for(int c=0;c<M;c++){
                    row[c]+=Strips[j][c];
                }

                sum=0;
                first=0;
                for(int m=0;m<M;m++){
                    sum+=row[m];
                    if(sum>K){
                        sum-=row[first];
                        first++;
                    }
                    area=(m-first+1)*(j-i+1);
                    if(area>maxarea){
                        maxarea=area;
                        cost=sum;
                    }
                    else if(area==maxarea){
                        cost=(sum<cost)?sum:cost;
                    }

                }

            }
        }
        cout<<"Case #"<<casenum<<": "<<maxarea<<" "<<cost<<endl;

    }

}
