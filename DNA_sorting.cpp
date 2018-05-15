#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;

bool compare(pair<string,int> num1,pair<string,int> num2){
    return num1.second<num2.second;
}

int main()
{
    int length,number,A,T,C,G,inversion;
    char c;
    string str;
    cin>>length>>number;

    vector<pair<string,int>> sortMap;
    while(number-->0){
        A=0,T=0,C=0,G=0;
        cin>>str;
        inversion=0;
        for(int i=0;i<length;i++){

            if(str[i]=='A'){
                A++;
                inversion=inversion+C+G+T;
            }
            else if(str[i]=='C'){
                C++;
                inversion=inversion+G+T;
            }
            else if(str[i]=='G'){
                G++;
                inversion=inversion+T;
            }
            else if(str[i]=='T'){
                T++;
            }
        }
        sortMap.push_back(make_pair(str,inversion));
    }

    sort(sortMap.begin(),sortMap.end(),compare);
    vector<pair<string,int>>::iterator it;
    for(it=sortMap.begin();it!=sortMap.end();it++){
        cout<<it->first<<endl;
    }
}