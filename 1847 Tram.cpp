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

typedef pair<int, int> PII;
const int INF = 2000000000;

int main(){

    int N,A,B,num,intersect;
    cin>>N>>A>>B;



    vector<PII> edges[110];

    for(int i=1;i<=N;i++){
        cin>>num;

        for(int j=0;j<num;j++){
            cin>>intersect;
            if(j==0){
                edges[i].push_back(make_pair(0,intersect));
            }
            else{
                edges[i].push_back(make_pair(1,intersect));
            }

        }
    }

    priority_queue<PII, vector<PII>, greater<PII> > Q;
    vector<int> dist(N+1, INF);
    Q.push(make_pair(0, A));
    dist[A] = 0;
    while (!Q.empty()) {
        PII p = Q.top();
        Q.pop();
        int here = p.second;
        if (here == B) break;
        if (dist[here] != p.first) continue;
        for (vector<PII>::iterator it = edges[here].begin(); it != edges[here].end(); it++) {
            if (dist[here] + it->first < dist[it->second]) {
                dist[it->second] = dist[here] + it->first;
                Q.push(make_pair(dist[it->second], it->second));
            }
        }
    }
    if(dist[B]!=INF)
        printf("%d\n", dist[B]);
    else
        printf("%d\n",-1);

}
