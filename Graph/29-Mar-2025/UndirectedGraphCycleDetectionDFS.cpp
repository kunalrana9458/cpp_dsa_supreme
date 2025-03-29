#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph{
    public:
    // first int -> u
    // second int -> v
    // third int -> weight
    unordered_map<int,list<int>> adjList;

    void addEdge(int u,int v,bool direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        if(direction == 0){
            // undirected edge
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else{
            // directed edge
            adjList[u].push_back(v);
        }
    }

    void printAdjList(int n){
        for(int i=0;i<n;i++){
            cout << i << ": ";
            cout << "{";
            for(auto j:adjList[i]){
                cout << "(" << j << ")";
            }
            cout << "}" << endl;
        }
    }   

    bool cycleDetectionDFS(int src,int parent,unordered_map<int,bool>& visited){
        visited[src]=true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                if(cycleDetectionDFS(nbr,src,visited)){
                    return true;
                }
            }
            else if (nbr != parent){
                return true;
            }
        }
        return false;
    }
};


int main(){
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(0,4,0);
    g.addEdge(4,3,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.printAdjList(5);
    unordered_map<int,bool> visited;
    bool ans=false;
    for(int i=0;i<5;i++){
        if(!visited[i]){
            ans = g.cycleDetectionDFS(i,-1,visited);
            if(ans){
                break; // because there is a possiblity that the next graph component may not have cycle but that one has a cycle 
            }
        }
    }
    if(ans) cout << "Cycle is Present" << endl;
    else cout << "Cycle Not Present" << endl;
    return 0;
}