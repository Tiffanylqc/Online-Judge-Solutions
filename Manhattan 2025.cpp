#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include <vector>

using namespace std;


int main()
{
    int NumOfCase,petrol,slice,scenario=0,square;
    cin>>NumOfCase;

    while(NumOfCase-->0){
        cin>>petrol;
        scenario++;
        cout<<"Scenario #"<<scenario<<":"<<endl;
        square=1+2*petrol;

        int middleSlice=petrol+1;
        for(int slice=1;slice<=2*petrol+1;slice++){
            cout<<"slice #"<<slice<<":"<<endl;
            int sliceDistance=abs(middleSlice-slice);
            int remainDistance=abs(petrol-sliceDistance);
            for(int i=1;i<=square;i++){
                for(int j=1;j<=square;j++){
                    if(abs(petrol+1-i)+abs(petrol+1-j)<=remainDistance){
                        cout<<sliceDistance+abs(petrol+1-i)+abs(petrol+1-j);
                    }
                    else{
                        cout<<'.';
                    }
                }
                cout<<endl;
            }
        }

        cout<<endl;
    }
}


