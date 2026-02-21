/*
Given two strings s and t of lengths m and n respectively, return
the minimum window substring of s such that every character in t
(including duplicates) is included in the window. If there is no
such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.empty())
            return "";

        unordered_map<char, int> countT, window;

        for (const char &ch : t)
            countT[ch]++;

        int have = 0;
        int need = countT.size();

        pair<int, int> res = {-1, -1};

        int resLen = INT_MAX;

        int l = 0;

        for (int r = 0; r < s.length(); r++)
        {
            char ch = s[r];

            window[ch]++;

            if (countT.count(ch) && window[ch] == countT[ch])
                have++;

            while (have == need)
            {
                if ((r - l + 1) < resLen)
                {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;

                if (countT.count(s[l]) && window[s[l]] < countT[s[l]])
                    have--;

                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};

int main()
{
    Solution sol;

    string s, t;

    cin >> s;
    cin >> t;

    cout << sol.minWindow(s, t);

    return 0;
}