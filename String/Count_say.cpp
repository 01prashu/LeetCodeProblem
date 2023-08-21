/*
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit.
Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

Example 1:

Input: n = 1
Output: "1"
Explanation: This is the base case.

Example 2:

Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
*/

#include <iostream>
#include <string>
using namespace std;
string solve(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        int c = 1;
        while (i < s.size() - 1 && s[i] == s[i + 1])
        {
            c++;
            i++;
        }
        result = result + to_string(c);
        result = result + s[i];
    }
    return result;
}
string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    if (n == 2)
    {
        return "11";
    }
    string ans = "11";
    for (int i = 3; i <= n; i++)
    {
        ans = solve(ans);
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    string ans=countAndSay(n);
    cout<<ans<<endl;
    return 0;
}