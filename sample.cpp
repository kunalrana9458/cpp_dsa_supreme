#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adjList;

    void addEdge(int u,int v,bool dir){
        if(dir == 1){
            adjList[u].push_back(v);
        }
        else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adjList){
            cout << i.first << ":{";
            for(auto j:i.second){
                cout << j << ",";
            }
            cout << "}" << endl;
        }
    }

    void topoSortDFS(int src,unordered_map<int,bool>& visited,
                    stack<int>& st){
        visited[src]=true;

        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                topoSortDFS(nbr,visited,st);
            }
        }
        st.push(src);
    }

    void topoSortBFS(){
        queue<int> q;
        unordered_map<int,int> inDegree;
        for(auto i:adjList){
            for(auto nbr:i.second){
                inDegree[nbr]++;
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);
    g.printAdjList();

    unordered_map<int,bool> visited;
    stack<int> st;
    g.topoSortDFS(0,visited,st);
    cout << "Print Topological Sort" << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
     
    return 0;
}