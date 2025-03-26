#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class Graph{
    public:
    // first int -> u
    // second int -> v
    // third int -> weight
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdge(int u,int v,int weight,bool direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        if(direction == 0){
            // undirected edge
            adjList[u].push_back({v,weight});
            adjList[v].push_back({u,weight});
        }
        else{
            // directed edge
            adjList[u].push_back({v,weight});
        }
    }

    void printAdjList(int n){
        for(int i=0;i<n;i++){
            cout << i << ": ";
            cout << "{";
            list<pair<int,int>> temp=adjList[i];
            for(auto j:temp){
                // j is a pair here
                cout << "(" << j.first << "," << j.second << ")";
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

    void bfsTraversal(int src){
        queue<int> q;
        unordered_map<int,bool> visited;
        // maintian intial state for queue
        q.push(src);

        while(!q.empty()){
            int frontNode=q.front();
            cout << frontNode << ",";
            q.pop();

            for(auto neighBour:adjList[frontNode]){
                // neighbour is a pair first valie is node and second value is weight
                int node=neighBour.first;
                int weight=neighBour.second;

                if(!visited[node]){
                    q.push(node);
                    visited[node]=true;
                }
            }
        }
    }

    void dfsTraversal_helper(int src,unordered_map<int,bool>& visited){
        // mark src as visited;
        if(visited[src]) return ;
        visited[src]=true;
        cout << src << ",";
        
        for(auto nbr:adjList[src]){
            // nbr is a pair of node and weight
            // first->node
            // second->weight
            int node=nbr.first;
            // if(!visited[node]){
                dfsTraversal_helper(node,visited);
            // }
        }
    }

    void dfsTraversal(int n){
        int src=0;
        unordered_map<int,bool> visited;
        dfsTraversal_helper(src,visited);
    }

};

int main()
{
    Graph g;
    g.addEdge(0,3,5,1);
    g.addEdge(0,5,6,1);
    g.addEdge(0,2,2,1);
    g.addEdge(2,5,7,1);
    g.addEdge(3,5,2,1);
    g.addEdge(5,4,3,1);
    g.addEdge(5,6,3,1);
    g.addEdge(4,1,1,1);
    g.addEdge(6,1,8,1);
    g.printAdjList(7);
    cout << "BFS:" ;
    g.bfsTraversal(0);
    cout << endl;
    cout << "DFS:";
    g.dfsTraversal(7);
    return 0;
}