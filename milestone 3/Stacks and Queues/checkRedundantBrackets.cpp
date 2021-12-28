#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool checkRedundantBrackets(string s)
{
    int count = 0;
    stack<char> s1;
    int n = s.length();
    int i = 0;

    // Iterate through the string.
    if(n==3){
        return true;
    }
    
    while (i < n)
    {
        if (s[i] != ')')
        {
            s1.push(s[i]);
            i++;
            continue;
        }
            while (s1.size() != 0)
            {
                if (s1.top() == '(' && count == 0)
                {
                    return true;
                }
                else if (s1.top() == '(' && count > 0)
                {
                    count = 0;
                    s1.pop();
                    i++;
                    break;
                }
                else
                {
                    count++;
                    s1.pop();
                }
            }
    }
    return false;
}


