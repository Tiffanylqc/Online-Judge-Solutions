#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

const int max_nodes=10000, log_max_nodes=15;
int num_nodes, log_num_nodes, root;
vector<int> children[max_nodes]; // children[i] contains the children of node i
int A[max_nodes][log_max_nodes+1]; // A[i][j] is the 2ˆj-th ancestor of node i, or -1 if that ancestor does not exist
int L[max_nodes]; // L[i] is the distance between node i and the root
// floor of the binary logarithm of n
int lb(unsigned int n)
{
    if(n==0)
        return -1;
    int p = 0;
    if (n >= 1<<16) { n >>= 16; p += 16; }
    if (n >= 1<< 8) { n >>= 8; p += 8; }
    if (n >= 1<< 4) { n >>= 4; p += 4; }
    if (n >= 1<< 2) { n >>= 2; p += 2; }
    if (n >= 1<< 1) { p += 1; }
    return p;
}
void DFS(int i, int l)
{
    L[i] = l;
    for(int j = 0; j < children[i].size(); j++)
        DFS(children[i][j], l+1);
}
int LCA(int p, int q)
{
    // ensure node p is at least as deep as node q
    if(L[p] < L[q])
        swap(p, q);
    // "binary search" for the ancestor of node p situated on the same level as q
    for(int i = log_num_nodes; i >= 0; i--)
        if(L[p] - (1<<i) >= L[q])
            p = A[p][i];
    if(p == q)
        return p;
    // "binary search" for the LCA
    for(int i = log_num_nodes; i >= 0; i--)
        if(A[p][i] != -1 && A[p][i] != A[q][i])
        {
            p = A[p][i];
            q = A[q][i];
        }
    return A[p][0];
}

int main()
{

    int NumOfCases;
    cin>>NumOfCases;
    map<int,int> tree;

    while(NumOfCases-->0){
        cin>>num_nodes;

        tree.clear();
        memset(A,0, sizeof(A));
        memset(L,0, sizeof(L));
        for(int i=0;i<max_nodes;i++){
            children[i].clear();
        }

        // read num_nodes, the total number of nodes
        log_num_nodes=lb(num_nodes);

        for(int i=0;i<num_nodes-1;i++){
            int parent,child;
            cin>>parent>>child;
            tree[child-1]=parent-1;
        }

        for(int i = 0; i < num_nodes; i++)
        {
            int p;

            if(tree.find(i)!=tree.end())
                p=tree[i];
            else
                p=-1;
            // read p, the parent of node i or -1 if node i is the root
            A[i][0] = p;
            if(p != -1)
                children[p].push_back(i);
            else
                root = i;
        }

        // precompute A using dynamic programming
        for(int j = 1; j <= log_num_nodes; j++)
            for(int i = 0; i < num_nodes; i++)
                if(A[i][j-1] != -1)
                    A[i][j] = A[A[i][j-1]][j-1];
                else
                    A[i][j] = -1;
        // precompute L
        DFS(root, 0);

        int query1,query2;
        cin>>query1>>query2;
        cout<<LCA(query1-1,query2-1)+1<<endl;
    }

    return 0;
}


