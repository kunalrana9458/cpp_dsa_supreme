// TopoLogical Sort
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<algorithm>
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

    void topoDfs(int src,unordered_map<int,bool>& visited,vector<int>& ans){
        visited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                topoDfs(nbr,visited,ans);
            }
        }
        // backtrack
        ans.push_back(src);
    }

    vector<int> topoSort(int V){
        unordered_map<int,bool> visited;
        vector<int> ans;
        int n=V;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                topoDfs(i,visited,ans);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){
    Graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 6, 1);
    g.addEdge(4, 7, 1);
    g.addEdge(5, 7, 1);
    g.addEdge(6, 8, 1);
    g.addEdge(7, 8, 1);
    int V=7;
    vector<int> ans = g.topoSort(V);
    cout << "Topological sort is:" << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
