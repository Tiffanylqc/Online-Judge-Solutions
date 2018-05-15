#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>

using namespace std;
#define MAXN 10010
string s;

struct Node{
    char c;
    int left;
    int right;
};
Node nodes[MAXN];
int cnt=1;


int buildTree(){
    stack<int> strS;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a'&&s[i]<='z'){
            nodes[cnt].c=s[i];
            nodes[cnt].left=0;
            nodes[cnt].right=0;
            strS.push(cnt);
            cnt++;

        }
        else{
            nodes[cnt].c=s[i];
            nodes[cnt].left=strS.top();
            strS.pop();
            nodes[cnt].right=strS.top();
            strS.pop();
            strS.push(cnt);
            cnt++;
        }
    }
    int root=strS.top();
    strS.pop();
    return root;
}

stack<int> BFS(int root){
    stack<int> answer;
    queue<int> Queue;
    Queue.push(root);

    while(!Queue.empty()){
        int nodeNum=Queue.front();
        answer.push(nodeNum);
        Node node=nodes[nodeNum];
        Queue.pop();


        if(node.right!=0)
            Queue.push(node.right);
        if(node.left!=0)
            Queue.push(node.left);
    }


    return answer;
}

int main()
{
    int NumOfInput;
    cin>>NumOfInput;

    while(NumOfInput-->0){
        cin>>s;
        cnt=1;
        int root=buildTree();

        stack<int> ans=BFS(root);

        while(!ans.empty()){
            cout<<nodes[ans.top()].c;
            ans.pop();
        }
        cout<<endl;
    }

    return 0;
}


