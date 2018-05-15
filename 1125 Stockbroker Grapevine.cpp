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
#define MAXN 105
#define INF (1<<20)
int dist[MAXN][MAXN];


int main(){

    int NumPeople,NumFriends,friends,time;

    while(cin>>NumPeople&&NumPeople!=0){


        for(int i=1;i<=NumPeople;i++){
            for(int j=1;j<=NumPeople;j++){
                if(i==j)
                    dist[i][j]=0;
                else
                    dist[i][j]=INF;
            }
        }

        for(int i=1;i<=NumPeople;i++){
            cin>>NumFriends;
            for(int j=0;j<NumFriends;j++){
                cin>>friends>>time;
                dist[i][friends]=time;
            }
        }

        for(int k=1;k<=NumPeople;k++){
            for(int i=1;i<=NumPeople;i++){
                for(int j=1;j<=NumPeople;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int min=INF;
        int tmp;
        int node;
        bool connected=true;
        for(int i=1;i<=NumPeople;i++){
            connected=true;
            tmp=-1;
            for(int j=1;j<=NumPeople;j++){
                if(dist[i][j]==INF){
                    connected=false;
                    break;
                }
                if(i!=j&&dist[i][j]>tmp){
                    tmp=dist[i][j];
                }
            }
            if(connected&&min>tmp){
                min=tmp;
                node=i;
            }
        }

        if(min==INF)
            cout<<"disjoint"<<endl;
        else{
            cout<<node<<" "<<min<<endl;
        }

    }

}
