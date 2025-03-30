#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool direction){
        // direction 0 -> undirected graph
        // direction 1 -> directed Graph
        if(direction == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        else{
            adj[u].push_back(v);
        }
    }

    void printAdjList(int n){
        for(int i=0;i<n;i++){
            cout << i << ": ";
            cout << "{";
            for(auto j:adj[i]){
                cout << "(" << j << ")";
            }
            cout << "}" << endl;
        }
    }  

    void shortestPathBfs(int src,int dest){
        // create visited track find parent mapping
        unordered_map<int,bool> vis;
        unordered_map<int,int> parent;
        queue<int> q;
        // maintian intial state of the queue
        q.push(src);
        parent[src]=-1;
        vis[src]=true;

        cout << "Shortest path bfs called" << endl;

        while(!q.empty()){
            // fetch the front node
            int node=q.front();
            q.pop();
            // process the nbr
            for(auto nbr:adj[node]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr] = true;
                    parent[nbr]=node;
                }
            }
        }
        vector<int> path;
        int node=dest;
        while(node != -1){
            path.push_back(node);
            node = parent[node];
        }
        // reverse the path
        reverse(path.begin(),path.end());
        // print the path
        for (int i = 0; i < path.size(); i++){
            cout << path[i] << "->";
        }
    }
    
 
};

int main()
{
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(2,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,3,0);
    g.printAdjList(5);
    int src=0;
    int dest=3;
    cout << "Before Shportest path:" << endl;
    g.shortestPathBfs(src,dest);
    return 0;
}