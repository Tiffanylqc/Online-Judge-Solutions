#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> roads[21];
int visited[21];
int reachable[21][21];
int fireDest;
int NumOfRoutes=0;

void backtrack(vector<int>path){
    if(path.back()==fireDest){
        NumOfRoutes++;
        for(int i=0;i<path.size();i++){
            if(i==0)
                cout<<path[i];
            else
                cout<<" "<<path[i];
        }
        cout<<endl;
        return;
    }

    int last=path.back();
    for(int i=0;i<roads[last].size();i++){

        int next=roads[last][i];
        if(visited[next]==0&&reachable[next][fireDest]==1){
            path.push_back(next);
            visited[next]=1;
            backtrack(path);
            path.pop_back();
            visited[next]=0;
        }
    }
}


int main(){


    int station1,station2;
    int CaseNum=1;
    while(cin>>fireDest){
        for(int i=0;i<21;i++)
            roads[i].clear();
        memset(reachable,0, sizeof(reachable));

        while(true){
            cin>>station1>>station2;
            if(station1==0&&station2==0)
                break;

            roads[station1].push_back(station2);
            roads[station2].push_back(station1);
            reachable[station1][station2]=1;
            reachable[station2][station1]=1;
        }

        for(int i=1;i<=20;i++){
            for(int j=1;j<=20;j++){
                for(int k=1;k<=20;k++){
                    if(reachable[i][k]&&reachable[k][j])
                        reachable[i][j]=1;
                }
            }
        }

        for(int i=0;i<21;i++) {
            if (roads[i].size() != 0 && roads[i].size() != 1)
                sort(roads[i].begin(), roads[i].end());
        }

        memset(visited,0, sizeof(visited));
        visited[1]=1;
        vector<int> path;
        path.push_back(1);
        NumOfRoutes=0;
        cout<<"CASE "<<CaseNum<<":"<<endl;
        backtrack(path);
        cout<<"There are "<<NumOfRoutes<<" routes from the firestation to streetcorner "<<fireDest<<"."<<endl;
        CaseNum++;
    }

}