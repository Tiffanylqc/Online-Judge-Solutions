#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 200010;

int N, M;
int tree[MAXN];
// add v to value at x
void set(int x, int v) {
    while(x <= N) {
        tree[x] += v;
        x += (x & -x);
    }
}
// get cumulative sum up to and including x
int get(int x) {
    int res = 0;
    while(x) {
        res += tree[x];
        x -= (x & -x);
    }
    return res;
}

int rightSmall[MAXN], leftLarge[MAXN];
long long ans[MAXN];
struct number
{
    int time;
    int index;
    int value;
};
struct number a[MAXN], tmp[MAXN];

void divideConquer(int L, int R)
{
    if (L >= R) return;
    int mid = (L+R)>>1;

    int l1 = L, l2 = mid+1;
    for(int i=L;i<=R;i++)
    {
        if (a[i].time <= mid)
            tmp[l1++] = a[i];
        else
            tmp[l2++] = a[i];
    }
    for(int i=L;i<=R;i++)
        a[i]=tmp[i];

    l1 = L;
    for(int i=mid+1;i<=R;i++){
        for (; l1<=mid && tmp[l1].index<tmp[i].index; ++l1)
            set(tmp[l1].value, 1);
        leftLarge[ tmp[i].time ] += (l1 - L) - get(tmp[i].value);
    }

    for(int i=L;i<=l1-1;i++){
        set(tmp[i].value, -1);
    }
    l1 = mid;

    for(int i=R;i>=mid+1;i--){
        for (; l1>=L && tmp[l1].index>tmp[i].index; --l1)
            set(tmp[l1].value, 1);
        rightSmall[ tmp[i].time ] += get(tmp[i].value - 1);
    }

    for(int i=l1+1;i<=mid;i++){
        set(tmp[i].value, -1);
    }

    divideConquer(L, mid);
    divideConquer(mid+1, R);
}

int pos[MAXN];
int main()
{
    while(cin>>N){
        cin>>M;
        memset(pos,0, sizeof(pos));
        memset(ans,0, sizeof(ans));
        memset(rightSmall,0, sizeof(rightSmall));
        memset(leftLarge,0, sizeof(leftLarge));
        memset(a,0, sizeof(a));
        memset(tmp,0, sizeof(tmp));

        for(int i=1;i<=N;i++){
            cin>>a[i].value;
            a[i].index=i;
            pos[a[i].value]=i;
        }
        int t, timeOfInsert = N;
        for(int i=1;i<=M;i++){
            cin>>t;
            a[pos[t]].time=timeOfInsert--;
        }
        for(int i=N;i>=1;i--){
            if(a[i].time==0){
                a[i].time=timeOfInsert--;
            }
        }
        divideConquer(1, N);
        for(int i=1;i<=N;i++){
            ans[i]=ans[i-1]+rightSmall[i] + leftLarge[i];
        }
        for(int i=N;i>=N-M+1;i--)
            cout << ans[i] << '\n';
    }

    return 0;
}


