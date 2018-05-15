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
int board[MAXN][MAXN];
int sum[MAXN];

int main(){
    int P,s,b,r1,c1,r2,c2,area,first,max;

    cin>>P;

    while(P-->0){
        cin>>s>>b;

        memset(board,0, sizeof(board));
        for(int i=0;i<b;i++){
            cin>>r1>>c1>>r2>>c2;
            for(int r=r1;r<=r2;r++){
                for(int c=c1;c<=c2;c++){
                    board[r][c]=1;
                }
            }
        }

        max=0;
        for(int i=1;i<=s;i++){
            memset(sum,0, sizeof(sum));
            for(int j=i;j<=s;j++){
                for(int k=1;k<=s;k++){
                    sum[k]+=board[j][k];
                }

                area=0;
                int c,r;
                first=1;
                for(int m=1;m<=s;m++){
                    if(sum[m]!=0){
                        first=m+1;
                    }
                    else{
                        area=(m-first+1)*(j-i+1);
                        max=(area>max)?area:max;
                    }
                }
            }
        }

        cout<<max<<endl;

    }
}

//int main(){
//
//    int NumOfCases,N,M,maxarea,area,sum,first,cost;
//    long long K;
//
//    cin>>NumOfCases;
//
//    for(int casenum=1;casenum<=NumOfCases;casenum++){
//        cin>>N>>M>>K;
//
//        for(int i=0;i<N;i++){
//            for(int j=0;j<M;j++){
//                cin>>Strips[i][j];
//            }
//        }
//        maxarea=-1;
//        area=0;
//        cost=0;
//
//        for(int i=0;i<N;i++){
//            memset(row,0, sizeof(row));
//            for(int j=i;j<N;j++){
//                for(int c=0;c<M;c++){
//                    row[c]+=Strips[j][c];
//                }
//
//                sum=0;
//                first=0;
//                for(int m=0;m<M;m++){
//                    sum+=row[m];
//                    if(sum>K){
//                        sum-=row[first];
//                        first++;
//                    }
//                    area=(m-first+1)*(j-i+1);
//                    if(area>maxarea){
//                        maxarea=area;
//                        cost=sum;
//                    }
//                    else if(area==maxarea){
//                        cost=(sum<cost)?sum:cost;
//                    }
//
//                }
//
//            }
//        }
//        cout<<"Case #"<<casenum<<": "<<maxarea<<" "<<cost<<endl;
//
//    }
//
//}
