//116
#include <iostream>
#include <vector>
using namespace std;

struct cell{
    int val;
    int child;
};

int main(){
    int col,row;

    while(scanf("%d %d",&row,&col)!=EOF){
        struct cell matrix[row][col];
        int i,j;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++) {
                cin >> matrix[i][j].val;
                matrix[i][j].child=-1;
            }
        }

        for(j=col-2;j>=0;j-- ){
            for(i=0;i<row;i++){
                int cellNum=matrix[i][j].val;
                matrix[i][j].val=cellNum+(matrix[(row+i-1)%row][j+1]).val;
                matrix[i][j].child=(row+i-1)%row;

                int sum=cellNum+matrix[i][j+1].val;
                if(sum<matrix[i][j].val){
                    matrix[i][j].val=sum;
                    matrix[i][j].child=i;
                }
                else if(sum==matrix[i][j].val&&matrix[i][j].child>i)
                    matrix[i][j].child=i;

                sum=cellNum+matrix[(row+i+1)%row][j+1].val;
                if(sum<matrix[i][j].val){
                    matrix[i][j].val=sum;
                    matrix[i][j].child=(row+i+1)%row;
                }
                else if(sum==matrix[i][j].val&&matrix[i][j].child>(row+i+1)%row)
                    matrix[i][j].child=(row+i+1)%row;
            }
        }

        int lowest=INT32_MAX;
        int lowRow=0;
        for(i=0;i<row;i++)
            if(matrix[i][0].val<lowest){
                lowest=matrix[i][0].val;
                lowRow=i;
            }

        vector<int>path;
        for(i=0;i<col;i++){
            path.push_back(lowRow+1);
            lowRow=matrix[lowRow][i].child;
        }
        for(i=0;i<path.size();i++){
            if(i==path.size()-1)
                cout<<path.at(i);
            else
                cout<<path.at(i)<<" ";
        }
        cout<<endl;
        cout<<lowest<<endl;
    }




}