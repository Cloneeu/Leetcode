/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
    determine if the input string is valid.

    An input string is valid if:

    - Open brackets must be closed by the same type of brackets.
    - Open brackets must be closed in the correct order.
    - Every close bracket has a corresponding open bracket of the same type.

    Example 1:
    Input: s = "()"
    Output: true

    Example 2:
    Input: s = "()[]{}"
    Output: true

    Example 3:
    Input: s = "(]"
    Output: false

    Example 4:
    Input: s = "([])"
    Output: true

    Example 5:
    Input: s = "([)]"
    Output: false

    Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> char_stack;

        for (char ch : s)
        {
            if (ch == '(' ||
                ch == '[' ||
                ch == '{')
            {
                char_stack.push(ch);
                continue;
            }

            if (char_stack.empty())
                return false;

            if ((char_stack.top() == '(' && ch == ')') ||
                (char_stack.top() == '[' && ch == ']') ||
                (char_stack.top() == '{' && ch == '}'))
                char_stack.pop();
            else 
                return false;

        }
        return char_stack.empty();
    }
};

int main()
{
    Solution sol;

    string s;

    cin >> s;

    cout << sol.isValid(s);

    return 0;
}