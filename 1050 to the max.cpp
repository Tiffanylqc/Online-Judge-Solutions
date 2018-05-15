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

int rectangle[101][101];
int arr[101];
int N;

int maxSum(){
    int sum=0,max=0;
    for(int i=0;i<N;i++){
        sum=(sum+arr[i]>arr[i])?(sum+arr[i]):arr[i];
        if(sum>max)
            max=sum;
    }
    return max;
}

int main()
{
    int num,max=0,sum;
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>num;
            rectangle[i][j]=num;
        }
    }

    for(int i=0;i<N;i++){
        memset(arr,0,sizeof(arr));

        for(int j=i;j<N;j++){
            for(int k=0;k<N;k++){
                arr[k]+=rectangle[j][k];
            }
            sum=maxSum();
            max=(sum>max)?sum:max;

        }
    }
    cout<<max<<endl;
}

