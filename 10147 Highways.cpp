#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;

class Edge{
public:
    int src;
    int dst;
    double length;
    Edge(int src,int dst,double length):src(src),dst(dst),length(length){

    }
};

class compare{
public:
    bool operator()(Edge edge1, Edge edge2){
        return edge1.length>edge2.length;
    }
};

int find(vector<int> &C, int x){
    return (C[x]==x)?x:C[x]=find(C,C[x]);
}

void merge(vector<int>& C, int x, int y){
    C[find(C,x)] = find(C,y);
}

int main(){

    int NumOfCases,NumOfTowns,NumOfHighways;
    cin>>NumOfCases;


    while(NumOfCases-->0){
        cin>>NumOfTowns;
        pair<int,int> towns[NumOfTowns+1];

        // read in towns' position
        int x,y;
        for(int i=1;i<=NumOfTowns;i++){
            cin>>x>>y;
            towns[i]=make_pair(x,y);
        }

        // set up union find
        vector<int> C(NumOfTowns+1);
        for(int i=0;i<=NumOfTowns;i++)
            C[i]=i;

        //read in existing highways
        cin>>NumOfHighways;
        int RemainHighways=NumOfTowns-1;
        for(int i=0;i<NumOfHighways;i++){
            cin>>x>>y;
            if(find(C,x)!=find(C,y)){
                merge(C,x,y);
                RemainHighways--;
            }
        }

        if(RemainHighways==0)
            cout << "No new highways need" << endl;
        else{
            // push all edges into priority queue
            priority_queue<Edge,vector<Edge>,compare> PQueue;
            double x1,x2,y1,y2;
            double dist,distx,disty;
            for(int i=1;i<=NumOfTowns;i++){
                for(int j=i+1;j<=NumOfTowns;j++){
                    x1=towns[i].first;
                    y1=towns[i].second;
                    x2=towns[j].first;
                    y2=towns[j].second;
                    dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                    PQueue.push(Edge(i,j,dist));
                }
            }

            while(RemainHighways!=0){
                Edge edge=PQueue.top();
                PQueue.pop();
                if(find(C,edge.src)!=find(C,edge.dst)){
                    cout<<edge.src<<" "<<edge.dst<<endl;
                    merge(C,edge.src,edge.dst);
                    RemainHighways--;
                }
            }
        }
        if(NumOfCases!=0)
            cout<<endl;
    }
}