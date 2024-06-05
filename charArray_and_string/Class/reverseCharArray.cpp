#include<iostream>
using namespace std;
int getLen(char arr[])
{
    int index = 0;
    int lenCnt = 0;
    while (arr[index] != '\0')
    {
        lenCnt++;
        index++;
    }
    return lenCnt;
}
void reverse(char arr[]){
    int i=0;
    int j=getLen(arr)-1;
    while(i<=j){
        swap(arr[i++],arr[j--]);
    }
}
int main()
{
    char arr[100];
    cout << "Enter the char array" << endl;
    cin >> arr;
    reverse(arr);
    cout << "After Reversal:" << arr << endl;
    return 0;
}