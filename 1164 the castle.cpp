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

int row,column;
int Map[51][51];
bool visited[51][51];

bool IsValid(int x,int y){
    if(x>=1&&x<=row&&y>=1&&y<=column)
        return true;
    return false;
}
int maxArea=0;
int area=0;

void dfs(int x, int y){
    if(!IsValid(x,y)){
//        maxArea=(maxArea>area)?maxArea:area;
        return;
    }

    if(visited[x][y]){
//        maxArea=(maxArea>area)?maxArea:area;
        return;
    }

    visited[x][y]=true;
    area++;
//    cout<<Map[x][y]<<" "<<(Map[x][y]&1)<<endl;
    if((Map[x][y]&1)==0){
        dfs(x,y-1);
    }
    if((Map[x][y]&2)==0){
        dfs(x-1,y);
    }
    if((Map[x][y]&4)==0){
        dfs(x,y+1);
    }
    if((Map[x][y]&8)==0){
        dfs(x+1,y);
    }

}

int main()
{
    cin>>row>>column;

    for(int i=1;i<=row;i++){
        for(int j=1;j<=column;j++){
            cin>>Map[i][j];
        }
    }

    int count=0;
    memset(visited,false, sizeof(visited));
    for(int i=1;i<=row;i++){
        for(int j=1;j<=column;j++){
            if(!visited[i][j]){
                count++;
                area=0;
                dfs(i,j);
                maxArea=(maxArea>area)?maxArea:area;
            }
        }
    }
    cout<<count<<endl<<maxArea<<endl;
}

