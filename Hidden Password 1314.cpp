#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct SuffixArray {
    const int L;
    string s;
    vector<vector<int> > P;
    vector<pair<pair<int,int>,int> > M;
    SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
        for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
        for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
            P.push_back(vector<int>(L, 0));
            for (int i = 0; i < L; i++)
                M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
            sort(M.begin(), M.end());
            for (int i = 0; i < L; i++)
                P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
        }
    }
    vector<int> GetSuffixArray() { return P.back(); }
};

int main() {
    int T;
    cin >> T;
    for (int caseno = 0; caseno < T; caseno++) {
        string s;
        int length;
        cin>>length;
        cin >> s;
        s=s+s+"}";
        SuffixArray array(s);
        vector<int> v=array.GetSuffixArray();
        int minIdx=0;
        int minPosition=v[0];
        for(int i=0;i<length;i++){
            if(v[i]<minPosition){
                minIdx=i;
                minPosition=v[i];
            }
        }
        cout<<minIdx<<endl;
    }
}