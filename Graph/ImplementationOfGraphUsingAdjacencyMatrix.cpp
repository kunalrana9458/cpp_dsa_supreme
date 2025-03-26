#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
    public:
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
            list<int> temp=adjList[i];
            for(auto j:temp){
                cout << j << ":";
            }
            cout << "}" << endl;
        }
        // for(auto i:adjList){
        //     cout << i.first << "->";
        //     for(auto j:i.second){
        //         cout << j << ",";
        //     }
        //     cout << endl;
        // }
    }

    bool cycleDetectionUsingBFS(int src,unordered_map<int,bool>& visited){
        queue<int> q;
        unordered_map<int,int> parent;
        
        q.push(src);
        visited[src]= true;
        parent[src] = -1;

        while(!q.empty()){
            int frontNode=q.front();
            q.pop();

            for(auto nbr:adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;
                }

                else if(visited[nbr] == true && nbr != parent[frontNode]) return true;
            }
        }
        return false;
    }

    bool cycleDetectionUsingDFS(int src){
        
    }

};

int main()
{
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.printAdjList(4);

    // good practice
    bool ans=false;
    unordered_map<int,bool> visited;
    for(int i=0;i<4;i++){
        if(!visited[i]){
            ans=g.cycleDetectionUsingBFS(i,visited);
            if(ans==true) break;
        }
    }
    if(ans) cout << "Cycle  Present" << endl;
    else cout << "Cycle Absent" << endl;
    return 0;
}