#include<iostream>
#include <string.h>
#include<algorithm>
#include<cstdio>
#include<string>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct Edge{
    int node1;
    int node2;
    int length;
};

struct compare
{
    bool operator()(const Edge& l, const Edge& r)
    {
        return l.length > r.length;
    }
};

int N,M;

int find(vector<int> &C, int x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }
void merge(vector<int> &C, int x, int y) { C[find(C, x)] = find(C, y); }

int main()
{

    cin>>N>>M;

    int v1,v2,length;
    priority_queue<Edge,vector<Edge>,compare> pq;
    Edge tmp;
    for(int i=0;i<M;i++){
        cin>>v1>>v2>>length;
        tmp.node1=v1;
        tmp.node2=v2;
        tmp.length=length;
        pq.push(tmp);
    }

    vector<int> C(N+1);
    for (int i = 0; i < N+1; i++) C[i] = i;
    int edge=0;
    int max=0;
    while(edge<N-1){
        tmp=pq.top();
        pq.pop();

        if(find(C,tmp.node1)!=find(C,tmp.node2)){
            merge(C,tmp.node1,tmp.node2);
            max=tmp.length;
            edge++;
        }
    }

    cout<<max<<endl;
}

