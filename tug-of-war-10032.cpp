#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_PEOPLE 101
#define MAX_TOTALWEIGHT 45000
int Weight[MAX_PEOPLE];
long long dp[MAX_TOTALWEIGHT];

int main(){
    int NumOfCases,NumOfPeople;
    cin>>NumOfCases;
    getchar();
    getchar();
    while(NumOfCases>0){
        cin>>NumOfPeople;

        memset(Weight,0, sizeof(int)*MAX_PEOPLE);
        memset(dp,0, sizeof(dp));
        int totWeight=0;
        for(int i=1;i<=NumOfPeople;i++){
            cin>>Weight[i];
            totWeight+=Weight[i];
        }

        dp[0]=1;
        for(int i=1;i<=NumOfPeople;i++){
            for(int j=totWeight/2;j>=Weight[i];j--){
                dp[j]|= (dp[j-Weight[i]]<<1);
            }
        }

        if(NumOfPeople%2==0){
            for(int j=totWeight/2;j>=0;j--){
                if(dp[j]&((long long)(1<<(NumOfPeople/2)))) {
                    cout<<j<<" "<<totWeight-j<<endl;
                    break;
                }
            }
        }
        else{
            for(int j=totWeight/2;j>0;j--){
                if(dp[j]&((long long)(1<<(NumOfPeople/2)))||dp[j]&((long long)(1<<(NumOfPeople/2+1)))){
                    cout<<j<<" "<<totWeight-j<<endl;
                    break;
                }
            }
        }

        getchar();
        getchar();
        NumOfCases--;
    }
}