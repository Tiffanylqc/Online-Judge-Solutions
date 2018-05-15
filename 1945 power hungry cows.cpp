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

int P;
bool vis[20500][105];

struct Pair{
    int num1;
    int num2;
    int step;
    Pair(int n1,int n2, int s){
//        if(n1>n2){
            num1=n1;
            num2=n2;
//        }
//        else{
//            num2=n1;
//            num1=n2;
//        }
        step=s;
    }
};

queue<Pair> WVS;

bool Add(int num1,int num2,int step){
    if(num1==P||num2==P)
        return true;

    if(num1<num2)
        swap(num1,num2);

    if(num1 == num2||num1 >= P + 101|| num2 >= 101)
        return false;
    if(!vis[num1][num2]){
        vis[num1][num2]=true;
        WVS.push(Pair(num1,num2,step));
    }
    return false;
}

int main()
{

    cin>>P;


    WVS.push(Pair(1,0,0));


    while(!WVS.empty()){
        Pair now=WVS.front();
        WVS.pop();
        int n1=now.num1;
        int n2=now.num2;
        int s=now.step;

//        if(n1==P||n2==P){
//            cout<<s<<endl;
//            break;
//        }

        if( Add(n1+n1,n2,s+1)|| Add(n1+n1,n1,s+1)|| Add(n1,n2+n2,s+1) ||Add(n2,n2+n2,s+1)||Add(n1+n2,n1,s+1)||Add(n1+n2,n2,s+1)||Add(n1,n1-n2,s+1)|| Add(n2,n1-n2,s+1)){
            cout<<s+1<<endl;
            break;
        }
    }

    return 0;
}

