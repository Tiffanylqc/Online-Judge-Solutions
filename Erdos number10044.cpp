#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
//gerg


#define ERDOS "Erdos, P."

map<string,int> nameToid;

int main() {
    int NumOfScen, NumOfPaper, NumOfName,start,end,NumOfAuthor;
    cin>>NumOfScen;
    set<int> adjList[10001];
    string book,name;
    vector<int> authorList;


    for(int k=1;k<=NumOfScen;k++){
        cin>>NumOfPaper>>NumOfName;
        getchar();
        NumOfAuthor=0;
        nameToid.clear();

        for(int i=0;i<10001;i++)
            adjList[i].clear();

        while(NumOfPaper-->0){
            getline(cin,book);
            authorList.clear();
            start=0;
            end=0;

            while(book[end]!=':'){
                if(book[end]=='.'&&book[end+1]==','){
                    name=book.substr(start,end-start+1);
                    start=end+3;
                    end=start;

                    if(nameToid.find(name)==nameToid.end()){
                        nameToid[name]=NumOfAuthor;
                        authorList.push_back(NumOfAuthor);
                        NumOfAuthor++;
                    }
                    else{
                        authorList.push_back(nameToid[name]);
                    }
                }
                else if(book[end]=='.'&&book[end+1]==':'){
                    name=book.substr(start,end-start+1);
                    start=end+1;
                    end=start;

                    if(nameToid.find(name)==nameToid.end()){
                        nameToid[name]=NumOfAuthor;
                        authorList.push_back(NumOfAuthor);
                        NumOfAuthor++;
                    }
                    else{
                        authorList.push_back(nameToid[name]);
                    }
                }
                else
                    end++;
            }

            //contruct the adjacency list

            for(int i=0;i<authorList.size();i++){
                for(int j=i+1;j<authorList.size();j++){
                    adjList[authorList[i]].insert(authorList[j]);
                    adjList[authorList[j]].insert(authorList[i]);
                }
            }
        }
//        map<string, int>::iterator it;
//        for(it=nameToid.begin();it!=nameToid.end();it++)
//            cout<<it->first<<" "<<it->second<<endl;
//
//        cout<<NumOfAuthor<<endl;
//        set<int>::iterator it2;
//        for(int i=0;i<NumOfAuthor;i++){
//            for(it2=adjList[i].begin();it2!=adjList[i].end();it2++)
//                cout<<*it2<<" ";
//            cout<<endl;
//        }

        int id,size,path;
        cout<<"Scenario "<<k<<endl;
        while(NumOfName-->0){
            getline(cin,name);
            if(nameToid.find(name)==nameToid.end()){
                cout<<name<<" "<<"infinity"<<endl;
                continue;
            }
            else{//search
                id=nameToid[name];
                int erdoNum=nameToid[ERDOS];
                set<int>::iterator it;

                int visited[NumOfAuthor];
                for(int l=0;l<NumOfAuthor;l++)
                    visited[l]=0;
                visited[id]=1;
                queue<int> Queue;
                for(it=adjList[id].begin();it!=adjList[id].end();it++){
                    if(visited[*it]!=1){
                        Queue.push(*it);
                        visited[*it]=1;
                    }
                }
                path=0;
                int flag=0;
                while(!Queue.empty()){
                    size=Queue.size();
                    path++;
                    while(size-->0){
                        id=Queue.front();
                        Queue.pop();
                        if(id==erdoNum){
                            flag=1;
                            break;
                        }
                        for(it=adjList[id].begin();it!=adjList[id].end();it++){
                            if(visited[*it]!=1){
                                Queue.push(*it);
                                visited[*it]=1;
                            }
                        }
                    }
                    if(flag==1){
                        cout<<name<<" "<<path<<endl;
                        break;
                    }
                }
                if(flag==0)
                    cout<<name<<" "<<"infinity"<<endl;
            }

        }
    }


    return 0;
}