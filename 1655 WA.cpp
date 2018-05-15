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
vector<int> Edge[20010];
int minBalance,numNode,nodes;
bool visited[20010];

int DFS(int root){
    visited[root]=true;
    int childBalance=0;
    int maxChild=0;
    int children=0;
    int tmp;

    for(int i=0;i<Edge[root].size();i++){
        if(!visited[Edge[root][i]]){
            tmp=DFS(Edge[root][i]);
            children+=tmp+1;
            childBalance=tmp+1;

            maxChild=max(maxChild,childBalance);

        }
    }
    maxChild=max(maxChild,nodes-children-1);
    if(maxChild<minBalance){
        minBalance=maxChild;
        numNode=1;
    }
    else if(maxChild==minBalance)
        numNode++;

    return children;
}

int main()
{
    int NumOfCases,node1,node2;
    cin>>NumOfCases;

    while(NumOfCases-->0){
        cin>>nodes;
        minBalance=20010;
        numNode=0;

        memset(visited,false, sizeof(visited));

        for(int i=0;i<nodes-1;i++){
            cin>>node1>>node2;
            Edge[node1].push_back(node2);
            Edge[node2].push_back(node1);
        }

        DFS(1);

        cout<<numNode<<" "<<minBalance<<endl;
    }

    return 0;
}

