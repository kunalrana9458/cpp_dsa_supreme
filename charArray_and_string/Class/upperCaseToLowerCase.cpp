#include <iostream>
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
int main()
{
    char arr[100];
    cout << "Enter the string" << endl;
    cin >> arr;
    int len = getLen(arr);
    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {                                // Check if the character is lowercase
            arr[i] = arr[i] - 'a' + 'A'; // Convert to uppercase
        }
    }
    cout << "Output is:" << arr << endl;
    return 0;
}