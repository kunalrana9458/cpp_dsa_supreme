#include<iostream>
#include<vector>
using namespace std;
 int solve(vector<vector<char>>& matrix,int m,int n,int i,int j,int& maxi){
        // base case if index i or j is out of bound
        if(i>=m || j>=n) return 0;
        // make three function calls 
        // one call is for the right direction
        int right=solve(matrix,m,n,i+1,j,maxi);
        // second call is for the downward direction
        int down=solve(matrix,m,n,i,j+1,maxi);
        // third call is for diagonal call
        int diagonal=solve(matrix,m,n,i+1,j+1,maxi);
        if(matrix[i][j] == '1'){
            int ans=1+min(right,min(down,diagonal));
            maxi=max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
        // return ans;
    }
int maximalSquare(vector<vector<char>>& matrix){
    int i=0;
    int j=0;
    int m=matrix.size();
    int n=matrix[0].size();
    int maxi=0;
    int ans=solve(matrix,m,n,i,j,maxi);
    return maxi*maxi;
}
int main()
{
    int m=4;
    int n=5;
    vector<vector<char>> matrix(m,vector<char>(n));
    matrix={{'1','0','1','0','0'}
           ,{'1','1','1','0','0'}
           ,{'1','1','1','1','1'}
           ,{'1','1','1','1','0'}};
    int ans=maximalSquare(matrix);
    cout << "Answer is:" << ans << endl;
    return 0;
}