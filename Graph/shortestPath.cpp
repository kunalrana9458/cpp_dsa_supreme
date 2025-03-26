#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<int>> adjList;
    void addEdge(int u,int v,bool dir){
        // dir-0 undirected graph 
        // dir-1 directed graph
        if(dir == 0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            adjList[u].push_back(v);
        }
    }

    void parentToChildMapping()

};
int main()
{
    
    return 0;
}