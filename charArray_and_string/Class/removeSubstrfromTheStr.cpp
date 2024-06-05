#include<iostream>
using namespace std;
int main()
{
    string full="daabcbaabcbc";
    string pattern="abc";
    while(full.find(pattern) != string::npos){
        // we will remove pattern string from full string
        // by finding its first index from pattern index 
        full.erase(full.find(pattern),pattern.length());
    }
    cout << "Answer is:" << full << endl;
    return 0;
}