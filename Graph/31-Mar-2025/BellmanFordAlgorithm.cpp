#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
#include<list>
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

    void bellmanFord(int src,int n){
        vector<int> dist(n,INT_MAX);
        // n-1 times loop
        for(int i=0;i<n-1;i++){
            // for each edge do relaxation
            for(auto a:adjList){
                for(auto b:a.second){
                    // a -> u and a.second->nbr of u and list 
                    // b->pair<int,int> , b.first -> v and b.second->weight
                    int u=a.first;
                    int v=b.first;
                    int wt=b.second;
                    if(dist[u] != INT_MAX && dist[u]+wt < dist[v]){
                        dist[v] = dist[u]+wt;
                    }
                }
            }
        }
    }
};

int main()
{
    cout << "Hello" << endl;
}