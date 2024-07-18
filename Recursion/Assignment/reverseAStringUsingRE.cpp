#include<iostream>
#include<string>
using namespace std;
void reverseStringUsingRE(string& str,int start,int end){
    // base case
    if(start>=end) return ;
    // swap the two char from i and j
    swap(str[start],str[end]);
    // recursive relation
    reverseStringUsingRE(str,start+1,end-1);
}
int main()
{
    string str="snkjgnsdfgsdngksdng";
    int start=0;
    int end=str.size()-1;
    reverseStringUsingRE(str,start,end);
    cout << str << endl;
    return 0;
}