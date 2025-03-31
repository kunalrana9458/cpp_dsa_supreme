#include<iostream>
#include<set>
#include<queue>
#include<unordered_map>
#include<list>
#include<limits.h>
using namespace std;

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
    
    void shortestDistanceDijkstra(int src,int n){
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;

        // maintain the intial state
        st.insert({0,src});
        dist[src]=0;
        
        while (!st.empty())
        {
            // find the smallest node from the set
            auto topElement = *(st.begin());
            int wt = topElement.first;
            int node = topElement.second;
            // pop current node
            st.erase(st.begin());
            // process the adjacent nodes
            for(auto nbr:adjList[node]){
                int nbrNode = nbr.first;
                int nbrWeight = nbr.second;
                if(dist[node]+nbrWeight < dist[nbrNode]){
                    // delete the odd entry and push new entry
                    auto result = st.find({dist[nbrNode],nbrNode});
                    if(result != st.end()){
                        st.erase(result);
                    }
                    dist[nbrNode] = wt+nbrWeight;
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        cout << "Distance is:" << endl;
        for(auto i:dist){
            cout << i << " ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,5,9,0);
    g.addEdge(0,3,6,0);
    g.addEdge(5,4,2,0);
    g.addEdge(4,3,11,0);
    g.addEdge(4,1,9,0);
    g.addEdge(4,2,10,0);
    g.addEdge(3,2,15,0);
    g.addEdge(5,1,14,0);
    g.addEdge(1,2,7,0);
    g.printAdjList(6);
    cout << "Dijkstra Algorithm is:" << endl;
    g.shortestDistanceDijkstra(0,6);
    return 0;
}