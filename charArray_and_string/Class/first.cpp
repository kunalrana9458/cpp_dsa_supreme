#include<iostream>
using namespace std;
int main(){
    char arr[100];
    cout << "Enter Your name" << endl;
    cin.getline(arr,1000,'A');
    cout << "Your name is:" << arr << endl;
    for(int i=0;i<5;i++){
        cout << arr[i] << " ";
    }
}



