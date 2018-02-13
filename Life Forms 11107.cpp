#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> ii;

#define MAX_N 100111                         
int T[MAX_N];                   // the input string, up to 100K characters
int n;                                        // the length of input string
int RA[MAX_N], tempRA[MAX_N];        // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];    // suffix array and temporary suffix array
int c[MAX_N];                                    // for counting/radix sort

char P[MAX_N];                  // the pattern string (for string matching)
int m;                                      // the length of pattern string

int Phi[MAX_N];                      // for computing longest common prefix
int PLCP[MAX_N];
int LCP[MAX_N];  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
// and current suffix T+SA[i]

void countingSort(int k) {                                         
    int i, sum, maxi = max(300, n);   
    memset(c, 0, sizeof c);                          // clear frequency table
    for (i = 0; i < n; i++)       // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)          // shuffle the suffix array if necessary
        tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)                     // update the suffix array SA
        SA[i] = tempSA[i];
}

void constructSA() {         
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i];                 // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;     // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) {       // repeat sorting process log n times
        countingSort(k);  // actually radix sort: sort based on the second item
        countingSort(0);          // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;             // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)                    // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
                    (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)                     // update the rank array RA
            RA[i] = tempRA[i];
        if (RA[SA[n-1]] == n-1) break;               // nice optimization trick
    }
}

void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;                                         // default value
    for (i = 1; i < n; i++)                            // compute Phi in O(n)
        Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {             // compute Permuted LCP in O(n)
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }            // special case
        while (T[i + L] == T[Phi[i] + L]) L++;       // L increased max n times
        PLCP[i] = L;
        L = max(L-1, 0);                             // L decreased max n times
    }
    for (i = 0; i < n; i++)                            // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
}

int Index[101];//record the index of separators(start from 0)
int NumOfDNA;

int owner(int idx) {
    for(int i=0;i<NumOfDNA-1;i++){
        if(idx>Index[i]&&idx<=Index[i+1])
            return i+2;

    }
    return 1;
}

int l,r;

bool judge(int x, int bo) {
    set<int> vis;
    vis.insert(owner(SA[0]));
    for (int i = 1; i < n; i++) {
        while (i < n && LCP[i] >= x) {
            vis.insert(owner(SA[i]));
            i++;
        }
        if (vis.size() * 2 > NumOfDNA) {
            if (bo == 0)
                return true;
            for (int j = 0; j < x; j++)
                printf("%c", T[SA[i - 1] + j]);
            printf("\n");
        }
        vis.clear();
        vis.insert(owner(SA[i]));
    }
    return false;
}

void solve() {
    if (!judge(1, 0)) {
        printf("?\n");
        return;
    }
    l = 1; r++;
    while (l < r) {
        int mid = (l + r) / 2;
        if (judge(mid, 0)) l = mid + 1;
        else r = mid;
    }
    l--;
    judge(l, 1);
}

int main() {
    char tmp[MAX_N];

    int halfNum;
    int flag=0;
    while(~scanf("%d", &NumOfDNA) && NumOfDNA){
        if(flag)
            printf("\n");
        else
            flag=1;

        if(NumOfDNA==1){
            scanf("%s",tmp);
            printf("%s\n",tmp);
            continue;
        }
        else{
            r=0;
            int tot=0;
            for(int i=0;i<NumOfDNA;i++){
                scanf("%s",tmp);
                for(int j=0;j<strlen(tmp);j++)
                    T[tot++]=tmp[j];

                Index[i]=tot;
                r=(r>strlen(tmp))?r:strlen(tmp);
                T[tot++]='z'+i+1;
            }

            n = tot;
            constructSA();                                              // O(n log n)
            computeLCP();                                                     // O(n)

            solve();
        }
    }

    return 0;
}