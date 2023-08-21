/*Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.
Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
*/
#include <iostream>
#include <string>
using namespace std;
bool checkrotateString(string s, string goal)
{
    if (s.length() != goal.length())
    {
        return false;
    }
    else
    {
        goal = goal + goal;
        if (goal.find(s) != string ::npos)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s , goal;
    cin>>s>>goal;
    bool ans=checkrotateString(s , goal);
    cout<<"Answer is: "<<ans<<endl;
    return 0;
}