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

#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

typedef long long LL;
typedef vector<LL> VLL;
typedef vector<vector<LL>> VVLL;
typedef pair<LL, int> PLLI;

struct Edge
{
    int from, to;
    LL cost;
    Edge(int from, int to, LL cost) :from(from), to(to), cost(cost) {}
};

typedef vector<Edge> VE;
typedef vector<vector<Edge>> VVE;

const LL maxCost = 0x3FFFFFFFFFFFFFFF;

struct DirectedGraph
{
    int nNodes;
    VVE adjList;

    DirectedGraph(int n) :nNodes(n), adjList(n + 1) {}
    void addEdge(int from, int to, LL cost) { adjList[from].push_back(Edge(from, to, cost)); }

    VVLL floydDist;
    void floyd()
    {
        floydDist = VVLL(nNodes + 1, VLL(nNodes + 1, maxCost));
        for (int i = 1; i <= nNodes; i++) floydDist[i][i] = 0;
        for (int i = 1; i <= nNodes; i++)
            for (int j = 0; j < (int)adjList[i].size(); j++)
                floydDist[adjList[i][j].from][adjList[i][j].to] = adjList[i][j].cost;
        for (int k = 1; k <= nNodes; k++)
            for (int i = 1; i <= nNodes; i++)
                for (int j = 1; j <= nNodes; j++)
                    if (floydDist[i][j] > floydDist[i][k] + floydDist[k][j])
                        floydDist[i][j] = floydDist[i][k] + floydDist[k][j];
    }

    VLL dijkstraDist;
    void dijkstra(int from, int to)
    {
        priority_queue<PLLI, vector<PLLI>, greater<PLLI>> Q;
        dijkstraDist = VLL(nNodes + 1, maxCost);
        dijkstraDist[from] = 0;
        Q.push(make_pair(0, from));
        while (!Q.empty())
        {
            PLLI p = Q.top();
            Q.pop();

            int u = p.second;
            if (to == u) break;
            if (dijkstraDist[u] != p.first) continue;

            VE& es = adjList[u];
            for (int i = 0; i < (int)es.size(); i++)
            {
                Edge& c = es[i];
                int v = c.to; LL w = c.cost;
                if (dijkstraDist[v] > dijkstraDist[u] + w)
                {
                    dijkstraDist[v] = dijkstraDist[u] + w;
                    Q.push(make_pair(dijkstraDist[v],v));
                }
            }
        }
    }

    VLL dijkstraDistSecond;
    void dijkstraSecondShortest(int from, int to) // backtracking allowed
    {
        priority_queue<PLLI, vector<PLLI>, greater<PLLI>> Q;
        dijkstraDist = VLL(nNodes + 1, maxCost);
        dijkstraDistSecond = VLL(nNodes + 1, maxCost);
        dijkstraDist[from] = 0; // dijkstraDistSecond[from] still INF
        Q.push(make_pair(0, from));
        while (!Q.empty())
        {
            PLLI p = Q.top();
            Q.pop();

            int u = p.second;
            if (dijkstraDistSecond[u] < p.first) continue; // must be strict less

            VE& es = adjList[u];
            for (int i = 0; i < (int)es.size(); i++)
            {
                Edge& c = es[i];
                int v = c.to; LL newDist = c.cost + p.first;
                if (newDist < dijkstraDist[v])
                {
                    swap(newDist, dijkstraDist[v]);
                    Q.push(make_pair(dijkstraDist[v], v));
                }
                if (newDist > dijkstraDist[v] && newDist < dijkstraDistSecond[v])
                {
                    dijkstraDistSecond[v] = newDist;
                    Q.push(make_pair(dijkstraDistSecond[v], v));
                }
            }
        }
    }

    VLL SPFADist;
    bool SPFA(int from)
    {
        queue<PLLI> q;
        vector<bool> inqueue(nNodes + 1, false);
        vector<int> visitCount(nNodes + 1, 0);
        SPFADist = VLL(nNodes + 1, maxCost);
        SPFADist[from] = 0;
        inqueue[from] = 1;
        q.push(make_pair(SPFADist[from], from));
        while (!q.empty())
        {
            PLLI p = q.front(); q.pop();
            LL udist = p.first; int u = p.second;
            inqueue[u] = false;
            if (visitCount[u]++ > nNodes) break;
            VE& edges = adjList[u];
            for (int i = 0; i < (int)edges.size(); i++)
            {
                int to = edges[i].to; LL w = edges[i].cost;
                if (SPFADist[u] + w < SPFADist[to])
                {
                    SPFADist[to] = SPFADist[u] + w;
                    if (!inqueue[to]) inqueue[to] = true, q.push(make_pair(SPFADist[to], to));
                }
            }
        }

        for(int i=0;i<adjList.size();i++){
            VE tmp=adjList[i];
            for(int j=0;j<tmp.size();j++){
                Edge e=tmp[j];
                if(SPFADist[e.from]+e.cost<SPFADist[e.to])
                    return true;
            }
        }

        return false;
    }
};



int main(){

    int NumOfCases,N,M,W,n1,n2,c;
    cin>>NumOfCases;

    while(NumOfCases-->0){
        cin>>N>>M>>W;

        struct DirectedGraph graph(N+1);

        for(int i=0;i<M;i++){
            cin>>n1>>n2>>c;
            graph.addEdge(n1,n2,c);
            graph.addEdge(n2,n1,c);
        }
        for(int i=0;i<W;i++){
            cin>>n1>>n2>>c;
            graph.addEdge(n1,n2,(-1)*c);
        }

        if(graph.SPFA(1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}
