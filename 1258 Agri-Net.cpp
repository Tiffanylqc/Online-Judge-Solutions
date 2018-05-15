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

struct Edge{
    int node1;
    int node2;
    int length;
};

struct compare{
    bool operator()(const Edge& l, const Edge& r){
        return l.length>r.length;
    }
};

int find(vector<int> &C, int x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }
void merge(vector<int> &C, int x, int y) { C[find(C, x)] = find(C, y); }

int N;

int main()
{
    while(cin>>N){
        int tmp;
        Edge e;
        priority_queue <Edge,vector<Edge>,compare> edges;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>tmp;
                if(j<=i)
                    continue;
                e.node1=i;
                e.node2=j;
                e.length=tmp;
                edges.push(e);
            }
        }

        vector<int> C(N);
        for (int i = 0; i < N; i++) C[i] = i;

        int num=0;
        long sum=0;
        while(num<N-1){
            e=edges.top();
            edges.pop();

            if(find(C,e.node1)!=find(C,e.node2)){
                merge(C,e.node1,e.node2);
                num++;
                sum+=e.length;
            }
        }

        cout<<sum<<endl;
    }



    return 0;
}

