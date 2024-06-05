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
bool checkPalindrome(char arr[]){
    int i=0;
    int j=getLen(arr)-1;
    while(i<=j){
        if(arr[i] != arr[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main()
{
    char arr[100];
    cout << "Enter the array" << endl;
    cin >> arr;
    bool ans=checkPalindrome(arr);
    cout << "Answer is:" << ans << endl;
    return 0;
}