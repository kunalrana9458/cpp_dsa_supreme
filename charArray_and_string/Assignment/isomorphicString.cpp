#include <iostream>
#include <unordered_map>
using namespace std;
bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> mpp;
    unordered_map<char, bool> isCharMapped;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (mpp.find(ch) == mpp.end() && isCharMapped[t[i]] == 0)
        {
            mpp[s[i]] = t[i];
            isCharMapped[t[i]] = true;
        }
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (mpp[s[i]] != t[i])
            return false;
    }
    return true;
}
int main()
{
    string s, t;
    cin >> s >> t;
    bool ans = isIsomorphic(s, t);
    cout << "Answer is:" << ans;
    // approach -2 we also solve that ques by using the normalise concept as used in the findandreplacePattern question in the class folder 
    return 0;
}