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

struct subset{
    int parent;
    int rank;
    int money;
};

int find(struct subset subsets[], int x){
    if(subsets[x].parent!=x)
        subsets[x].parent=find(subsets,subsets[x].parent);
    return subsets[x].parent;

}

void Union(struct subset subsets[],int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }

    else if (subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main()
{
    int NumOfCases,NumOfPeople,NumOfFriend;
    cin>>NumOfCases;

    while(NumOfCases-->0){
        cin>>NumOfPeople>>NumOfFriend;
        int money;
        struct subset Friends[NumOfPeople];
        for (int i = 0; i < NumOfPeople; i++){
            cin>>money;
            Friends[i].money=money;
            Friends[i].parent=i;
            Friends[i].rank=0;
        }

        int n1,n2;
        for(int i=0;i<NumOfFriend;i++){
            cin>>n1>>n2;
            Union(Friends,n1,n2);
        }

        int sum[NumOfPeople];
        memset(sum,0, sizeof(sum));
        int flag=false;
        for(int i=0;i<NumOfPeople;i++){
            sum[find(Friends,i)]+=Friends[i].money;

        }

        for(int i=0;i<NumOfPeople;i++){
            if(sum[i]!=0){
                flag=true;
                break;
            }
        }
        if(flag)
            cout<<"IMPOSSIBLE"<<endl;
        else
            cout<<"POSSIBLE"<<endl;
    }

    return 0;
}
