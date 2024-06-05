#include<iostream>
using namespace std;
int main(){
    string str = "Hello jee kaise ho saare";
    string word = "kaise ho";
    int ans=str.find(word);
    cout << "Answer is:" << ans ;
    return 0;
}