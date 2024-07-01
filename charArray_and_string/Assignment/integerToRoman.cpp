#include<iostream>
#include<map>
using namespace std;
 string intToRoman(int num) {
        int values[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string ans="";
        string romanValues[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;i<13;i++){
            while(num >= values[i]){
                ans += romanValues[i];
                num -= values[i];
            }
        }
        return ans;
    }
int main()
{
    int num;
    cin >> num;
    string ans=intToRoman(num);
    cout << "Answer is:" << ans << endl;
    return 0;
}