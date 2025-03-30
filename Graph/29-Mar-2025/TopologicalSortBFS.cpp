#include<iostream>
#include<unordered_map>
#include<queue>
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
    
    vector<int> topoSort(int n){
        // find the indegree of the nodes of the graph
        unordered_map<int,int> indegree;
        vector<int> ans; 
        for(int i=1;i<=7;i++){
            for(auto itr:adjList[i]){
                indegree[itr]++;
            }
        }

        // find the nodes having indegree 0 and push it into queue
        queue<int> q;
        for(int i=1;i<=7;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // process the queue
        while (!q.empty())
        {
            // process the front node of the queue
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto nbr:adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
   
};

int main()
{
    cout << "Jai Shree Ram" << endl;
    // create a graph
    Graph g;
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,7,1);
    g.printAdjList(7);
    cout << "Topological Sort is:" << endl;
    vector<int> ans = g.topoSort(7);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}