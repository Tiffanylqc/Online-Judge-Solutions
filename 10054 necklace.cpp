#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <list>
using namespace std;

struct Edge;
typedef list<Edge>::iterator iter;

struct Edge{
    int next_vertex;
    iter reverse_edge;
    Edge(int next_vertex):next_vertex(next_vertex){}
};

const int max_vertices=51;
int num_vertices;
list<Edge> adj[max_vertices];
vector<int> path;

void find_path(int v){
    while(adj[v].size()>0){
        int vn=adj[v].front().next_vertex;
        adj[vn].erase(adj[v].front().reverse_edge);
        adj[v].pop_front();
        find_path(vn);
    }
    path.push_back(v);
}

void add_edge(int a,int b){
    adj[a].push_front(Edge(b));
    iter ita=adj[a].begin();
    adj[b].push_front(Edge(a));
    iter itb=adj[b].begin();
    ita->reverse_edge=itb;
    itb->reverse_edge=ita;
}
int main(){
    int NumOfCases;
    cin>>NumOfCases;
    int NumOfBeads;

    int casenum=1;
    int color1,color2;
    while(NumOfCases-->0){

        cin>>NumOfBeads;

        for(int i=1;i<max_vertices;i++)
            adj[i].clear();

        while(NumOfBeads-->0){
            cin>>color1>>color2;
            add_edge(color1,color2);
        }
        path.clear();
        find_path(color1);

        cout<<"Case #"<<casenum<<endl;
        if(path.front()==path.back()){
            for(int i=0;i<path.size()-1;i++){
                cout<<path[i]<<" "<<path[i+1]<<endl;
            }
            cout<<endl;
        }
        else{
            cout<<"some beads may be lost"<<endl<<endl;
        }

        casenum++;
    }

}