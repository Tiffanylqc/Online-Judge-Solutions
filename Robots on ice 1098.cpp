#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define MAXLENGTH 8
bool grid[MAXLENGTH][MAXLENGTH];

int row,column,r1,r2,r3,c1,c2,c3,step1,step2,step3,pathNum;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

bool inRange(int nowRow,int nowCol){
    if(nowRow>=0 && nowRow<row && nowCol>=0 && nowCol<column)
        return true;
    return false;
}

int distance(int srcR, int srcC, int desR, int desC){
    return abs(srcR-desR)+abs(srcC-desC);
}

bool isConnected(){
    queue<pair<int,int>> Queue;
    bool visited[row][column];
    memset(visited,false, sizeof(visited));

    bool flag=false;
    for(int i=0;i<MAXLENGTH;i++){
        for(int j=0;j<MAXLENGTH;j++){
            if(!grid[i][j]) {
                Queue.push(make_pair(i, j));
                visited[i][j] = true;
                flag = true;
                break;
            }
        }
        if(flag)
            break;
    }

    while(Queue.size()!=0){
        pair<int,int>& pos=Queue.front();
        Queue.pop();
        int r=pos.first;
        int c=pos.second;
        for(int i=0;i<4;i++){
            int newRow=r+dx[i];
            int newCol=c+dy[i];
            if(inRange(newRow,newCol)&&visited[newRow][newCol]==false&&grid[newRow][newCol]==false){
                Queue.push(make_pair(newRow,newCol));
                visited[newRow][newCol]=true;
            }
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(visited[i][j]==false&&grid[i][j]==false)
                return false;
        }
    }
    return true;
}

void visit(int nowRow,int nowCol,int step){
    if(nowRow==0&&nowCol==1){
        if(step==row*column){
            pathNum++;
        }
        return;
    }

    //we are at step1,step2,step3 at inappropriate time
    if(nowRow==r1&&nowCol==c1&&step!=step1
            ||nowRow==r2&&nowCol==c2&&step!=step2
            ||nowRow==r3&&nowCol==c3&&step!=step3)
        return;

    //we are not at (r1,c1) (r2,c2) (r3,c3) at step1,step2,step3
    if(step==step1&&(nowRow!=r1||nowCol!=c1)
            ||step==step2&&(nowRow!=r2||nowCol!=c2)
            ||step==step3&&(nowRow!=r3||nowCol!=c3))
        return;

    //we are before step1,step2,step3 but our distance to step1,step2,step3 is larger than the required step to go
    if(step<step1 && distance(nowRow,nowCol,r1,c1)>(step1-step))
        return;
    else if(step<step2 && distance(nowRow,nowCol,r2,c2)>(step2-step))
        return;
    else if(step<step3 && distance(nowRow,nowCol,r3,c3)>(step3-step))
        return;

    //whether we can reach remaining positions
    if(!isConnected())
        return;


    //check urgent neighbor which must be visited next
    int urgent=0;
    int direction=-1;
    for(int i=0;i<4;i++){
        int newRow=nowRow+dx[i];
        int newCol=nowCol+dy[i];
        if(inRange(newRow,newCol)&&grid[newRow][newCol]==false&&!(newRow==0&&newCol==1)){
            int neighbor=0;
            for (int j = 0; j < 4; j++) {
                int nr = newRow + dx[j], nc = newCol + dy[j];
                if (inRange(nr, nc) && !grid[nr][nc])
                    neighbor++;
            }
            if(neighbor==0)
                return;
            if(neighbor==1){
                urgent++;
                direction=i;
            }
        }
    }

    if (urgent > 1) return;
    else if (urgent == 1) {
        grid[nowRow + dx[direction]][ nowCol+ dy[direction]] = true;
        visit(nowRow + dx[direction], nowCol+ dy[direction], step + 1);
        grid[nowRow + dx[direction]][nowCol+ dy[direction]] = false;
        return;
    }

    //search for 4 directions
    for(int i=0;i<4;i++){
        int newRow=nowRow+dx[i];
        int newCol=nowCol+dy[i];
        if(!inRange(newRow,newCol)||grid[newRow][newCol])
            continue;

        grid[newRow][newCol]=true;
        visit(newRow,newCol,step+1);
        grid[newRow][newCol]=false;
    }
}

int main(){
    cin>>row>>column;
    int CaseNum=1;
    while(row!=0&&column!=0){
        cin>>r1>>c1>>r2>>c2>>r3>>c3;

        step1=row*column/4;
        step2=row*column/2;
        step3=row*column*3/4;

        memset(grid,false, sizeof(grid));
        grid[0][0]=true;
        pathNum=0;

        visit(0,0,1);

        cout<<"Case "<<CaseNum<<": "<<pathNum<<endl;
        CaseNum++;
        cin>>row>>column;
    }
}