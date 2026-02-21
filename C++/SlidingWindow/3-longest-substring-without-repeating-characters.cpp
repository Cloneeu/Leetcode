/*
    Given a string s, find the length of the longest substring without duplicate characters.

    Example 1:

    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
    Example 2:

    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.
    Example 3:

    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> char_set;
        int res = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++)
        {
            while (char_set.count(s[right]))
            {
                char_set.erase(s[left]);
                left++;
            }
            char_set.insert(s[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main()
{

    Solution sol;

    string str;

    cin >> str;

    cout << sol.lengthOfLongestSubstring(str);

    return 0;
}