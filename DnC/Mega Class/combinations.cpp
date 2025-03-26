#include <iostream>
#include <vector>
using namespace std;
void solve(int n, int k, vector<int> &output, vector<vector<int>> &ans, int index)
{
    if (k == 0)
    { //  base case k==0 wala lenge na ki index>k wala base case
        ans.push_back(output);
        return;
    }
    for (int i = index; i <= n; i++)
    {
        output.push_back(i);
        solve(n, k - 1, output, ans, i + 1);
        output.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> output;
    solve(n, k, output, ans, 1);
    return ans;
}
int main()
{
    int n,k;
    cin >> n >> k;
    vector<vector<int>> ans=combine(n,k);
    cout << "Answer is:" << endl;
    for(auto i:ans){
        for(auto j:i) cout << j << " ";
        cout << endl;
    }
    return 0;
}