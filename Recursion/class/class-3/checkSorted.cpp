 #include<iostream>
 using namespace std;
 bool isSorted(int arr[],int size,int index){
    if(index+1 >= size) return true;
    if(arr[index]>arr[index+1]) return false;
    bool checkOtherPart=isSorted(arr,size,index+1);
    return checkOtherPart;
 }
 int main()
 {
    int size=6;
    int arr[6]={10,15,25,35,30,95};
    int index=0;
    bool ans=isSorted(arr,size,index);
    cout << ans << endl; 
    return 0;
 }