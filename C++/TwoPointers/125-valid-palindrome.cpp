/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase
letters and removing all non-alphanumeric characters, it reads the same forward and
backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;

        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
                left++;

            while (right > left && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution sol;

    cout << sol.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}