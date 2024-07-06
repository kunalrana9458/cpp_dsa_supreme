#include<iostream>
#include<string>
using namespace std;
void findSubsequence(string& str,int index,string output){
    if(index >= str.size()){
        cout << output << endl;
        return;
    }
    // exclude call for the string
    // output.push_back(str[index]);
    char ch=str[index];
    findSubsequence(str,index+1,output+ch);
    // include call for the string
    findSubsequence(str,index+1,output);
    // pop back from the string 
    // output.pop_back();
}
int main()
{
    string str="abc";
    int index=0;
    string output;
    findSubsequence(str,index,output);
    return 0;
}