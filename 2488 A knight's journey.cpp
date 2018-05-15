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

int dx[8]={-1,1,-2,2,-2,2,-1,1};
int dy[8]={-2,-2,-1,-1,1,1,2,2};

bool inBoard(int x,int y){
    if(x>=1 && x<=row && y>=1 && y<=column)
        return true;
    return false;
}
string result;
int flag=0;
bool visited[27][27];
void dfs(int x,int y,string s,int count){
    if(!inBoard(x,y))
        return;
    if(flag==1)
        return;
    if(count==row*column){
        result=s;
        flag=1;
        return;
    }
//    string tmps=s;
    for(int i=0;i<8;i++){
        if(inBoard(x+dx[i],y+dy[i])&&!visited[x+dx[i]][y+dy[i]]){
            visited[x+dx[i]][y+dy[i]]=true;
            char colc='A'+(y+dy[i]-1);
            char rowc='1'+(x+dx[i]-1);
//            s=tmps+colc+rowc;
            dfs(x+dx[i],y+dy[i],s+colc+rowc,count+1);
//            s=tmps;
            visited[x+dx[i]][y+dy[i]]=false;
        }

    }

}

int main()
{
    int NumOfCases;
    cin>>NumOfCases;

    for(int casenum=1;casenum<=NumOfCases;casenum++){
        cin>>row>>column;

        result="";
        memset(visited,false, sizeof(visited));
        visited[1][1]=true;
        flag=0;
        dfs(1,1,"A1",1);

        cout<<"Scenario #"<<casenum<<":"<<endl;
        if(result==""){
            cout<<"impossible"<<endl<<endl;
        }
        else
            cout<<result<<endl<<endl;
    }

    return 0;
}

