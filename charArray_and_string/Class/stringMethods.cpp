#include<iostream>
using namespace std;
int main()
{
    string name="Maharana Pratap";

    auto it = name.begin();

    while(it!=name.end()){
        cout << *it << " ";
        it++;
    }
    name.clear(); // clear the data
    cout << endl;
    cout << name.empty() << endl;

    // cout << name.at(0) << endl;
    // cout << name.front() << endl;
    // cout << name.back() << endl;
    // cout << name.length() << endl;
    return 0;
}
