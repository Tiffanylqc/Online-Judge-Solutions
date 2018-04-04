#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;

#define MAXNUM 20
const int INF = 0x3f3f3f3f;
int row,column;
int tr,tc;
int sr,sc,br,bc;
string path;

char maze[MAXNUM][MAXNUM];
int directions[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//[row,column] right(east) left(west) down(south) up(north)
char push[4]={'E','W','S','N'};
char walk[4]={'e','w','s','n'};
bool visPerson[MAXNUM][MAXNUM];
bool visBox[MAXNUM][MAXNUM];

struct point{
    int x;
    int y;
};

struct state{
    int br,bc;//position of box
    int pr,pc;//position of person
    int cnt;
    vector<int> directions;
    string path;//current path
};

class compare{
public:
    bool operator()(state state1, state state2){
        return state1.cnt>state2.cnt;
    }
};

bool ValidPos(int r,int c){
    return (r>=0)&&(r<row)&&(c>=0)&&(c<column);
}

bool BfsPerson(int br,int bc,int pr,int pc,int backR,int backC, string& tmpPath){
    queue<state> Q;
    state s,currentS,newS;
    s.pr=pr;
    s.pc=pc;
    s.path="";
    Q.push(s);

    int r,c,nextR,nextC;
    memset(visPerson,false, sizeof(visPerson));
    visPerson[br][bc]=true;
    while(!Q.empty()){
        currentS=Q.front();
        Q.pop();

        r=currentS.pr;
        c=currentS.pc;

        //arrive at <backR,backC>
        if(r==backR && c==backC){
            tmpPath=currentS.path;
            return true;
        }

        if(visPerson[r][c])
            continue;
        visPerson[r][c]=true;

        for(int i=0;i<4;i++){
            nextR=r+directions[i][0];
            nextC=c+directions[i][1];
            if(ValidPos(nextR,nextC) && !visPerson[nextR][nextC] && maze[nextR][nextC]!='#'){
                newS.pr=nextR;
                newS.pc=nextC;
                newS.path=currentS.path+walk[i];
                Q.push(newS);
            }
        }
    }

    return false;
}

bool judgePerson(state s){
    int backR,backC;
    int boxr,boxc,personc,personr;
    boxr=br;
    boxc=bc;
    personc=sc;
    personr=sr;
    string tmpPath;
    string result="";
    for(int i=0;i<s.directions.size();i++){
        tmpPath="";
        backR=boxr-directions[s.directions[i]][0];
        backC=boxc-directions[s.directions[i]][1];
        if(BfsPerson(boxr,boxc,personr,personc,backR,backC, tmpPath)){
            result=result+tmpPath;
            result=result+push[s.directions[i]];
            personc=boxc;
            personr=boxr;
            boxr=boxr+directions[s.directions[i]][0];
            boxc=boxc+directions[s.directions[i]][1];
        }
        else
            return false;
    }
    cout<<result<<endl;
    return true;
}

// outer bfs-> determine whether box can be moved to the target place
bool BfsBox(int pr, int pc, int br, int bc){
//    priority_queue<state,vector<state>, compare> Q;
    queue<state> Q;
    state s,currentS,newS;
    s.pr=sr;
    s.pc=sc;
    s.br=br;
    s.bc=bc;
    s.path="";
    s.cnt=0;
    Q.push(s);

    int r,c,nextR,nextC,backR,backC;
    int mark[MAXNUM][MAXNUM];
    memset(mark, INF, sizeof(mark));
    while(!Q.empty()){
        currentS=Q.front();
        Q.pop();

        r=currentS.br;
        c=currentS.bc;

        //enumerate 4 directions
        for(int i=0;i<4;i++){
            nextR=r+directions[i][0];
            nextC=c+directions[i][1];
            backR=r-directions[i][0];
            backC=c-directions[i][1];

            string tmpPath="";
            if(ValidPos(nextR,nextC) && ValidPos(backR,backC) && maze[nextR][nextC]!='#' && maze[backR][backC]!='#'){
                    newS=currentS;
                    newS.br=nextR;
                    newS.bc=nextC;
                    newS.pr=currentS.br;
                    newS.pc=currentS.bc;

                    if(tr==newS.br&&tc==newS.bc){
                        newS.directions.push_back(i);
                        if(judgePerson(newS))
                            return true;
                    }
                    else{
                        newS.cnt++;
                        if(newS.cnt>=mark[newS.br][newS.bc])
                            continue;
                        mark[newS.br][newS.bc]=newS.cnt;
                        newS.directions.push_back(i);
                        Q.push(newS);

                    }

            }
        }
    }

    return false;
}

int main(){
//    int sr,sc,br,bc;
    int mazeNum=1;
    while(true){
        cin>>row>>column;
        if(row==0&&column==0)
            break;

        // read in maze
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cin>>maze[i][j];
                if(maze[i][j]=='S'){
                    sr=i;
                    sc=j;
                }
                else if(maze[i][j]=='B'){
                    br=i;
                    bc=j;
                }
                else if(maze[i][j]=='T'){
                    tr=i;
                    tc=j;
                }

            }
        }
        path="";

        cout<<"Maze #"<<mazeNum<<endl;
        if(BfsBox(sr,sc,br,bc)){
            cout<<endl;
        } else
            cout<<"Impossible."<<endl<<endl;

        mazeNum++;
    }

}
