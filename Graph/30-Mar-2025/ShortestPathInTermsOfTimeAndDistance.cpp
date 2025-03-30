#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
#include<limits.h>
#include<stack>
using namespace std;

// Only Applicable for DAG
class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;
    void addEdge(int u,int v,int w,bool direction){
        // 0->undirected graph 
        // 1->directed Graph 
        if(direction == 0){
            adjList[u].push_back({v,w});
            adjList[v].push_back({u,w});
        }
        else{
            adjList[u].push_back({v,w});
        }
    }

    void printAdjList(int n){
        for(int i=0;i<n;i++){
            cout << i << ":";
            for(auto itr:adjList[i]){
                int edge = itr.first;
                int weight = itr.second;
                cout << "{" << edge << "," << weight << "}" << "  ";
            }
            cout << endl;
        }
    }

    void topologicalSort(int src,stack<int>& st,unordered_map<int,bool>& visited){
        // mark current node as a viisted
        visited[src]=true;

        // process the neighbouring node
        for(auto nbr:adjList[src]){
            if(!visited[nbr.first]){
                topologicalSort(nbr.first,st,visited);
            }
        }

        // push node into the stack to find a valid topo sort
        st.push(src);
    }

    vector<int> shortestPath(int n){
        stack<int> topoSort;
        vector<int> distance(n); // vector to store shortest distance to each and every node
        unordered_map<int,bool> visited;
        // handle for the disconnected components


        for(int i=0;i<n;i++){
            if(!visited[i]){
                topologicalSort(i,topoSort,visited);
            }
        }

        // intialise the distance vector to Infinity
        for(int i=0;i<distance.size();i++){
            distance[i] = 1e9;
        }
        // intialise for the source node distance
        distance[0] = 0;
        // process the whole stack now

        while(!topoSort.empty()){
            // fetch the top node
            int node = topoSort.top();
            topoSort.pop();
            // process for the neighbour
            for(auto nbr:adjList[node]){
                int nbrNode = nbr.first;
                int weight = nbr.second;
                if(weight+distance[node] < distance[nbrNode]){
                    distance[nbrNode] = weight + distance[node];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(distance[i]==1e9){
                distance[i] = -1; // means that node is unreachable
            }
        }
        return distance;
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,13,1);
    g.addEdge(0,4,3,1);
    g.addEdge(1,2,7,1);
    g.addEdge(1,4,1,1);
    g.addEdge(3,2,2,1);
    g.addEdge(4,3,6,1);
    int n=5;
    vector<int> ans = g.shortestPath(n);
    cout << "Shortest Path from the Souce node to all nodes:" << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}