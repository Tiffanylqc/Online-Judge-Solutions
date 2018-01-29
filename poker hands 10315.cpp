#include <iostream>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

#define STRAIGHTFLUSH (pow(2,33))
#define FOUROFKIND (pow(2,32))
#define FULLHOUSE (pow(2,31))
#define FLUSH (pow(2,30))
#define STRAIGHT (pow(2,29))
#define THREEOFKIND (pow(2,28))
#define TWOPAIRS (pow(2,27))
#define PAIRS (pow(2,26))

struct Card{
    int valueInt;
    char value;
    char suit;
};
int valueToInt(char c){
    if(isdigit(c))
        return c-'0';
    else if(c=='T')
        return 10;
    else if(c=='J')
        return 11;
    else if(c=='Q')
        return 12;
    else if(c=='K')
        return 13;
    else //if(c=='A')
        return 14;
}

void getHands(string input, Card* white, Card* black){
    int count=0;
    int i;
    for(i=0;count<5;){
        black[count].value=input[i];
        black[count].suit=input[i+1];
        black[count].valueInt=valueToInt(input[i]);
        i+=3;
        count++;
    }
    count=0;
    for(;count<5;){
        white[count].value=input[i];
        white[count].suit=input[i+1];
        white[count].valueInt=valueToInt(input[i]);
        i+=3;
        count++;
    }
}

bool cmp(Card a, Card b){
    if(a.valueInt<b.valueInt)
        return true;
    return false;
}

bool isStraight(Card* hand){
    for(int i=1;i<5;i++)
        if(hand[i-1].valueInt+1!=hand[i].valueInt)
            return false;
    return true;
}

bool isFlush(Card* hand){
    for(int i=1;i<5;i++)
        if(hand[i].suit!=hand[i-1].suit)
            return false;
    return true;
}

bool isFourKind(Card* hand){
    if( hand[0].valueInt == hand[3].valueInt ||
            hand[1].valueInt == hand[4].valueInt )
        return true;
    return false;
}

bool isThreeKind( Card* hand ){
    if( hand[0].valueInt == hand[2].valueInt ||
            hand[1].valueInt == hand[3].valueInt ||
            hand[2].valueInt == hand[4].valueInt )
        return true;
    return false;
}

bool isFullHouse( Card* hand ){
    if((hand[0].valueInt == hand[2].valueInt &&
            hand[3].valueInt == hand[4].valueInt)||
       (hand[2].valueInt == hand[4].valueInt &&
               hand[0].valueInt == hand[1].valueInt))
        return true;
    return false;
}

long long pokerHandRank(Card* hand){
    long long rank=0;
    if(isStraight(hand)&&isFlush(hand)) {
        rank += STRAIGHTFLUSH;
        rank+=pow(2,hand[4].valueInt-2);
        return rank;
    }

    if(isFourKind(hand)){
        rank+=FOUROFKIND;
        rank+=pow(2,hand[1].valueInt-2);
        return rank;
    }

    if(isFullHouse(hand)){
        rank+=FULLHOUSE;
        rank+=pow(2,hand[2].valueInt-2);
        return rank;
    }

    if(isFlush(hand)){
        rank+=FLUSH;
        rank+=pow(2,hand[0].valueInt-2);

        for(int i=1;i<5;i++)
            if(hand[i].valueInt!=hand[i-1].valueInt)
                rank+=pow(2,hand[i].valueInt-2);
        return rank;
    }

    if(isStraight(hand)){
        rank+=STRAIGHT;
        rank+=pow(2,hand[4].valueInt-2);
        return rank;
    }

    if(isThreeKind(hand)){
        rank+=THREEOFKIND;
        rank+=pow(2,hand[2].valueInt-2);
        return rank;
    }

    /* two pair */
    if( hand[0].valueInt == hand[1].valueInt &&
        hand[2].valueInt == hand[3].valueInt ){
//        cout<<"yes"<<endl;
        rank+=TWOPAIRS;
        rank+=pow(2,hand[3].valueInt+11);
//        cout<<hand[3].valueInt<<" "<<rank<<endl;
        rank+=pow(2,hand[1].valueInt+11);
//        cout<<hand[1].valueInt<<" "<<rank<<endl;
        rank+=pow(2,hand[4].valueInt-2);
//        cout<<hand[4].valueInt<<" "<<rank<<endl;
        return rank;
    }
    if( hand[1].valueInt == hand[0].valueInt &&
        hand[3].valueInt == hand[4].valueInt ){
        rank+=TWOPAIRS;
        rank+=pow(2,hand[4].valueInt+11);
        rank+=pow(2,hand[1].valueInt+11);
        rank+=pow(2,hand[2].valueInt-2);
        return rank;
    }
    if( hand[1].valueInt == hand[2].valueInt &&
        hand[3].valueInt == hand[4].valueInt ){
        rank+=TWOPAIRS;
//        cout<<"yes"<<endl;
        rank+=pow(2,hand[4].valueInt+11);
//        cout<<hand[4].valueInt<<" "<<rank<<endl;
        rank+=pow(2,hand[2].valueInt+11);
//        cout<<hand[2].valueInt<<" "<<rank<<endl;
        rank+=pow(2,hand[0].valueInt-2);
//        cout<<hand[0].valueInt<<" "<<rank<<endl;
//        cout<<rank;
        return rank;
    }

    /* pair */
    if( hand[0].valueInt == hand[1].valueInt ) {
        rank += PAIRS;
        rank+=pow(2,hand[4].valueInt-2);
        rank+=pow(2,hand[1].valueInt+11);
        rank+=pow(2,hand[3].valueInt-2);
        rank+=pow(2,hand[2].valueInt-2);
        return rank;
    }
    if( hand[1].valueInt == hand[2].valueInt ) {
        rank+=PAIRS;
        rank+=pow(2,hand[0].valueInt-2);
        rank+=pow(2,hand[4].valueInt-2);
        rank+=pow(2,hand[3].valueInt-2);
        rank+=pow(2,hand[2].valueInt+11);
        return rank;
    }

    if( hand[2].valueInt == hand[3].valueInt ) {
        rank+=PAIRS;
        rank+=pow(2,hand[4].valueInt-2);
        rank+=pow(2,hand[1].valueInt-2);
        rank+=pow(2,hand[3].valueInt+11);
        rank+=pow(2,hand[0].valueInt-2);
        return rank;
    }
    if( hand[3].valueInt == hand[4].valueInt ) {
        rank+=PAIRS;
        rank+=pow(2,hand[0].valueInt-2);
        rank+=pow(2,hand[1].valueInt-2);
        rank+=pow(2,hand[3].valueInt+11);
        rank+=pow(2,hand[2].valueInt-2);
        return rank;
    }

    else{
        rank+=pow(2,hand[4].valueInt-2);
        rank+=pow(2,hand[1].valueInt-2);
        rank+=pow(2,hand[3].valueInt-2);
        rank+=pow(2,hand[2].valueInt-2);
        rank+=pow(2,hand[0].valueInt-2);
    }
    return rank;
}

int main() {
    string input;
    Card white[5];
    Card black[5];

    while(getline(cin,input)){
        getHands(input, white, black);
        sort(black,black+5,cmp);
        sort(white,white+5,cmp);
        long long blackRank=pokerHandRank(black);
        long long whiteRank=pokerHandRank(white);

        if(whiteRank>blackRank)
            cout<<"White wins."<<endl;
        else if(whiteRank<blackRank)
            cout<<"Black wins."<<endl;
        else
            cout<<"Tie."<<endl;
//        for(int i=0;i<5;i++){
//            cout<<black[i].value<<" "<<black[i].suit<<endl;
//            cout<<white[i].value<<" "<<white[i].suit<<endl;
//        }
    }

    return 0;
}