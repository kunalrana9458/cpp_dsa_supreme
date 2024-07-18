#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
 void addNumbers(string& num1,string& num2,int i,int j,string& ans,int carry){
        if(i<0 && j<0){
            if(carry != 0){
                ans.push_back(carry+'0');
            }
            return ;
        } 
        int digit1=(i>=0?num1[i]:'0')-'0';
        int digit2=(j>=0?num2[j]:'0')-'0';
        int sum=digit1+digit2+carry;
        int digit=sum%10;
        carry=sum/10;
        ans.push_back(digit+'0');
        addNumbers(num1,num2,i-1,j-1,ans,carry);
    }
 string addStrings(string num1, string num2) {
        int len1=num1.size();
        int len2=num2.size();
        string ans="";
        addNumbers(num1,num2,len1-1,len2-1,ans,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main()
{
    string num1,num2;
    cin >> num1 >> num2;
    string ans=addStrings(num1,num2);
    cout << "Answer is:" << ans << endl;
    return 0;
}