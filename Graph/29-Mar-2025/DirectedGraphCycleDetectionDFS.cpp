#include<iostream>
#include<unordered_map>
#include<list>
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
        for(int i=1;i<=n;i++){
            cout << i << ": ";
            cout << "{";
            for(auto j:adjList[i]){
                cout << "(" << j << ")";
            }
            cout << "}" << endl;
        }
    }   

    bool detectCycleDfs(int src,unordered_map<int,bool>& pathTracker,unordered_map<int,bool>& visited){
        // add current node into the pathTracker
        visited[src] = true;
        pathTracker[src] = true;

        // call for the other adjacent nodes
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                if(detectCycleDfs(nbr,pathTracker,visited)){
                    return true;
                }
            }
            else if(visited[nbr] == true  && pathTracker[nbr] == true){
                return true;
            }
        }
        pathTracker[src] = false;

        return false;
    }

};

int main(){
    Graph g;
    g.addEdge(1,2,1);
    g.addEdge(2,4,1);
    g.addEdge(4,7,1);
    g.addEdge(7,6,1);
    g.addEdge(6,5,1);
    g.addEdge(5,4,1);
    g.addEdge(1,3,1);
    g.printAdjList(7);
    unordered_map<int,bool> pathTracker;
    unordered_map<int,bool> visited;
    bool ans = g.detectCycleDfs(1,pathTracker,visited);
    cout << ans;
    if(ans) cout << "Cycle is Present" << endl;
    else cout << "Cycle Not Found" << endl;
    return 0;
}