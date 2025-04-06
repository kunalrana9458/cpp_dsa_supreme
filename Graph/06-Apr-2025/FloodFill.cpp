#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            // create a queue for the bfs traversal
            queue<pair<int,int>> positions; // used to track of row and col of the image grid
            int pixel=image[sr][sc];
            positions.push({sr,sc});
            vector<int> dx={0,0,1,-1};
            vector<int> dy={1,-1,0,0};
            while(!positions.empty()){
                pair<int,int> points=positions.front();
                positions.pop();
                int x=points.first;
                int y=points.second;
                if(image[x][y]==pixel){
                    image[x][y]=color;
                }
                // push adjacent elements into the queue
                for(int i=0;i<4;i++){
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(newX<0 || newY<0 || newX>=image.size() || newY>=image[0].size() ||
                       image[newX][newY]!=pixel){
                        continue;
                    }
                    if(image[newX][newY] != color){
                      positions.push({newX,newY});
                    }
                }
            }
            return image;
        }
    };