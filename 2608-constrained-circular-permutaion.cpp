#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAXNUM 14

int size;
int sum;
int permNum;
int second;
bool visited[MAXNUM];

void dfs(int totNum,int prev1, int prev2){
    if(totNum==size){
        if(prev2+prev1+1<=sum&&prev1+1+second<=sum){
            permNum++;
        }
        return;
    }

    for(int i=2;i<=size;i++){
        if(visited[i]==false){
            if(prev1+prev2+i<=sum){
                visited[i]=true;
                dfs(totNum+1,i,prev1);
                visited[i]=false;
            }
        }
    }
}

int main(){
    int NumOfCases;
    cin>>NumOfCases;

    while(NumOfCases-->0){
        cin>>size;
        cin>>sum;
        permNum=0;
        memset(visited,false, sizeof(visited));

        visited[1]=true;

        for(int i=2;i<=size;i++){
            if(1+i<sum){
                second=i;
                visited[i]=true;
                dfs(2,i,1);
                visited[i]=false;
            }
        }

        cout<<"Permutation size:    "<<size<<endl;
        cout<<"Maximum triplet sum: "<<sum<<endl;
        cout<<"Valid permutations:  "<<permNum/2<<endl;
        if(NumOfCases!=0)
            cout<<endl;
    }
}