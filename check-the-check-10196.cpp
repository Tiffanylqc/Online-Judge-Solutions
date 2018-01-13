/*SOLUTION FOR 10196 UVA*/

#include <iostream>
using namespace std;

int checkBoard(char board[8][8], int i, int j){

    switch(board[i][j]){
        case 'k':
        case 'K':
            return 0;
        case 'p':{
            if(i+1<=7&&j-1>=0&&board[i+1][j-1]=='K')
                return 2;
            if(i+1<=7&&j+1<=7&&board[i+1][j+1]=='K')
                return 2;
            return 0;
        }
        case 'P':{
            if(i-1>=0&&j-1>=0&&board[i-1][j-1]=='k')
                return 1;
            if(i-1>=0&&j+1<=7&&board[i-1][j+1]=='k')
                return 1;
            return 0;
        }
        case 'n':{
            if(i-2>=0&&j-1>=0&&board[i-2][j-1]=='K')
                return 2;
            if(i-2>=0&&j+1<=7&&board[i-2][j+1]=='K')
                return 2;
            if(i-1>=0&&j-2>=0&&board[i-1][j-2]=='K')
                return 2;
            if(i+1<=7&&j-2>=0&&board[i+1][j-2]=='K')
                return 2;
            if(i+2<=7&&j-1>=0&&board[i+2][j-1]=='K')
                return 2;
            if(i+2<=7&&j+1<=7&&board[i+2][j+1]=='K')
                return 2;
            if(i+1<=7&&j+2<=7&&board[i+1][j+2]=='K')
                return 2;
            if(i-1>=0&&j+2<=7&&board[i-1][j+2]=='K')
                return 2;
            return 0;
        }
        case 'N':{
            if(i-2>=0&&j-1>=0&&board[i-2][j-1]=='k')
                return 1;
            if(i-2>=0&&j+1<=7&&board[i-2][j+1]=='k')
                return 1;
            if(i-1>=0&&j-2>=0&&board[i-1][j-2]=='k')
                return 1;
            if(i+1<=7&&j-2>=0&&board[i+1][j-2]=='k')
                return 1;
            if(i+2<=7&&j-1>=0&&board[i+2][j-1]=='k')
                return 1;
            if(i+2<=7&&j+1<=7&&board[i+2][j+1]=='k')
                return 1;
            if(i+1<=7&&j+2<=7&&board[i+1][j+2]=='k')
                return 1;
            if(i-1>=0&&j+2<=7&&board[i-1][j+2]=='k')
                return 1;
            return 0;
        }
        case 'b':{
            //left up
            int k=1;
            while(i-k>=0&&j-k>=0){
                if(board[i-k][j-k]=='K')
                    return 2;
                else if(board[i-k][j-k]!='.')
                    break;
                k++;
            }
            k=1;
            //right down
            while(i+k<=7&&j+k<=7){
                if(board[i+k][j+k]=='K')
                    return 2;
                else if(board[i+k][j+k]!='.')
                    break;
                k++;
            }
            k=1;
            //right up
            while(i-k>=0&&j+k<=7){
                if(board[i-k][j+k]=='K')
                    return 2;
                else if(board[i-k][j+k]!='.')
                    break;
                k++;
            }
            k=1;
            //left down
            while(i+k<=7&&j-k>=0){
                if(board[i+k][j-k]=='K')
                    return 2;
                else if(board[i+k][j-k]!='.')
                    break;
                k++;
            }
            return 0;
        }

        case 'B':{
            //left up
            int k=1;
            while(i-k>=0&&j-k>=0){
                if(board[i-k][j-k]=='k')
                    return 1;
                else if(board[i-k][j-k]!='.')
                    break;
                k++;
            }
            k=1;
            //right down
            while(i+k<=7&&j+k<=7){
                if(board[i+k][j+k]=='k')
                    return 1;
                else if(board[i+k][j+k]!='.')
                    break;
                k++;
            }
            k=1;
            //right up
            while(i-k>=0&&j+k<=7){
                if(board[i-k][j+k]=='k')
                    return 1;
                else if(board[i-k][j+k]!='.')
                    break;
                k++;
            }
            k=1;
            //left down
            while(i+k<=7&&j-k>=0){
                if(board[i+k][j-k]=='k')
                    return 1;
                else if(board[i+k][j-k]!='.')
                    break;
                k++;
            }
            return 0;
        }

        case 'r':{
            //up
            int k=1;
            while(i-k>=0){
                if(board[i-k][j]=='K')
                    return 2;
                else if(board[i-k][j]!='.')
                    break;
                k++;
            }
            //down
            k=1;
            while(i+k<=7){
                if(board[i+k][j]=='K')
                    return 2;
                else if(board[i+k][j]!='.')
                    break;
                k++;
            }
            //left
            k=1;
            while(j-k>=0){
                if(board[i][j-k]=='K')
                    return 2;
                else if(board[i][j-k]!='.')
                    break;
                k++;
            }
            //right
            k=1;
            while(j+k<=7){
                if(board[i][j+k]=='K')
                    return 2;
                else if(board[i][j+k]!='.')
                    break;
                k++;
            }
            return 0;
        }

        case 'R':{
            //up
            int k=1;
            while(i-k>=0){
                if(board[i-k][j]=='k')
                    return 1;
                else if(board[i-k][j]!='.')
                    break;
                k++;
            }
            //down
            k=1;
            while(i+k<=7){
                if(board[i+k][j]=='k')
                    return 1;
                else if(board[i+k][j]!='.')
                    break;
                k++;
            }
            //left
            k=1;
            while(j-k>=0){
                if(board[i][j-k]=='k')
                    return 1;
                else if(board[i][j-k]!='.')
                    break;
                k++;
            }
            //right
            k=1;
            while(j+k<=7){
                if(board[i][j+k]=='k')
                    return 1;
                else if(board[i][j+k]!='.')
                    break;
                k++;
            }
            return 0;
        }

        case 'q':{
            //up
            int k=1;
            while(i-k>=0){
                if(board[i-k][j]=='K')
                    return 2;
                else if(board[i-k][j]!='.')
                    break;
                k++;
            }
            //down
            k=1;
            while(i+k<=7){
                if(board[i+k][j]=='K')
                    return 2;
                else if(board[i+k][j]!='.')
                    break;
                k++;
            }
            //left
            k=1;
            while(j-k>=0){
                if(board[i][j-k]=='K')
                    return 2;
                else if(board[i][j-k]!='.')
                    break;
                k++;
            }
            //right
            k=1;
            while(j+k<=7){
                if(board[i][j+k]=='K')
                    return 2;
                else if(board[i][j+k]!='.')
                    break;
                k++;
            }
            //left up
            k=1;
            while(i-k>=0&&j-k>=0){
                if(board[i-k][j-k]=='K')
                    return 2;
                else if(board[i-k][j-k]!='.')
                    break;
                k++;
            }
            k=1;
            //right down
            while(i+k<=7&&j+k<=7){
                if(board[i+k][j+k]=='K')
                    return 2;
                else if(board[i+k][j+k]!='.')
                    break;
                k++;
            }
            k=1;
            //right up
            while(i-k>=0&&j+k<=7){
                if(board[i-k][j+k]=='K')
                    return 2;
                else if(board[i-k][j+k]!='.')
                    break;
                k++;
            }
            k=1;
            //left down
            while(i+k<=7&&j-k>=0){
                if(board[i+k][j-k]=='K')
                    return 2;
                else if(board[i+k][j-k]!='.')
                    break;
                k++;
            }
            return 0;
        }
        case 'Q':{
            //up
            int k=1;
            while(i-k>=0){
                if(board[i-k][j]=='k')
                    return 1;
                else if(board[i-k][j]!='.')
                    break;
                k++;
            }
            //down
            k=1;
            while(i+k<=7){
                if(board[i+k][j]=='k')
                    return 1;
                else if(board[i+k][j]!='.')
                    break;
                k++;
            }
            //left
            k=1;
            while(j-k>=0){
                if(board[i][j-k]=='k')
                    return 1;
                else if(board[i][j-k]!='.')
                    break;
                k++;
            }
            //right
            k=1;
            while(j+k<=7){
                if(board[i][j+k]=='k')
                    return 1;
                else if(board[i][j+k]!='.')
                    break;
                k++;
            }
            //left up
            k=1;
            while(i-k>=0&&j-k>=0){
                if(board[i-k][j-k]=='k')
                    return 1;
                else if(board[i-k][j-k]!='.')
                    break;
                k++;
            }
            k=1;
            //right down
            while(i+k<=7&&j+k<=7){
                if(board[i+k][j+k]=='k')
                    return 1;
                else if(board[i+k][j+k]!='.')
                    break;
                k++;
            }
            k=1;
            //right up
            while(i-k>=0&&j+k<=7){
                if(board[i-k][j+k]=='k')
                    return 1;
                else if(board[i-k][j+k]!='.')
                    break;
                k++;
            }
            k=1;
            //left down
            while(i+k<=7&&j-k>=0){
                if(board[i+k][j-k]=='k')
                    return 1;
                else if(board[i+k][j-k]!='.')
                    break;
                k++;
            }
            return 0;
        }
        default:
            return 0;
    }
}


int main() {

    char board[8][8];
    int i,j;
    int inCheck=0,gameNum=1;

    while(true){
        /*STEP ONE: read in the board*/
        int endOfGame=1;
        for(i=0;i<8;i++)
            for(j=0;j<8;j++){
                cin>>board[i][j];
                if(board[i][j]!='.')
                    endOfGame=0;
            }

        if(endOfGame==1){
            break;
        }

        inCheck=0;
        /*STEP TWO: check position on the board*/
        for(i=0;i<8&&inCheck==0;i++){
            for(j=0;j<8&&inCheck==0;j++){
                inCheck=checkBoard(board,i,j);
            }
        }

        if(inCheck==0)
            cout<<"Game #"<<gameNum<<": no king is in check."<<endl;
        else if(inCheck==1)
            cout<<"Game #"<<gameNum<<": black king is in check."<<endl;
        else
            cout<<"Game #"<<gameNum<<": white king is in check."<<endl;

        gameNum++;
    }


    return 0;
}