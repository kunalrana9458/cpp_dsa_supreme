#include<iostream>
using namespace std;
int getLen(char arr[]){
     int index=0;
    int lenCnt=0;

    while(arr[index] != '\0'){
        lenCnt++;
        index++;
    }
    return lenCnt;
}
int main()
{
    char arr[100];
    cout << "Enter the char array" << endl;
    cin >> arr;
    int ans=getLen(arr);
    cout << "Answer is:" << ans << endl;
}


