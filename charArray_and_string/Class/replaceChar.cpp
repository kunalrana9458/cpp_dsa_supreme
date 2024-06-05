#include<iostream>
using namespace std;
int main()
{
    char ch[100];
    cout << "Enter the String" << endl;
    cin >> ch;
    for(int i=0;i<100;i++){
        if(ch[i] == '@'){
            ch[i] = '_';
        }
    }
    cout << "Output is:" << ch << endl;
    return 0;
}