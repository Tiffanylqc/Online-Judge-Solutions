#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& tree, int start, int end, vector<int>& path, int pre ){
    if(path.back()==end)
        return true;
    int i;
    for(i=0;i<tree[start].size();i++){
        if(tree[start][i]==pre)
            continue;
        path.push_back(tree[start][i]);
        if(dfs(tree,tree[start][i],end,path,start))
            return true;
        path.pop_back();
    }
    return false;
}


int main() {
    int NumOfLeaf, i,j, start, end, NumOfTest,length;
    cin>>NumOfLeaf;

    vector<vector<int>> tree(NumOfLeaf+1);

    while(NumOfLeaf!=0){
        //read in the paths
        tree=vector<vector<int>>(NumOfLeaf+1);
        for(i=0;i<NumOfLeaf-1;i++){
            cin>>start>>end;
            tree[start].push_back(end);
            tree[end].push_back(start);
        }

        cin>>NumOfTest;
        vector<int> path;
        for(i=0;i<NumOfTest;i++){
            cin>>start>>end;
            path.clear();
            path.push_back(start);
            dfs(tree,start,end,path,-1);
            length=path.size();
            if(length%2==1)
                cout<<"The fleas meet at "<<path[length/2]<<"."<<endl;
            else{
                if(path[length/2]<path[length/2-1])
                    cout<<"The fleas jump forever between "<<path[length/2]<<" and "<<path[length/2-1]<<"."<<endl;
                else
                    cout<<"The fleas jump forever between "<<path[length/2-1]<<" and "<<path[length/2]<<"."<<endl;
            }
        }

        cin>>NumOfLeaf;
    }



    return 0;
}