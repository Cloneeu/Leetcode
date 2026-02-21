/*
    You are given a string s and an integer k. You can choose any character of
    the string and change it to any other uppercase English character. You can
    perform this operation at most k times.

    Return the length of the longest substring containing the same letter you
    can get after performing the above operations.

    Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.
    Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.

    Constraints:

    1 <= s.length <= 105
    s consists of only uppercase English letters.
    0 <= k <= s.length
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int res = 0;
        unordered_map<char, int> contador;

        int left = 0;
        int maxfrec = 0;

        for (int right = 0; right < s.size(); right++)
        {
            contador[s[right]]++;
            maxfrec = max(maxfrec, contador[s[right]]);

            while ((right - left + 1) - maxfrec > k)
            {
                contador[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

int main()
{
    Solution sol;

    string str;

    int k;

    cin >> str;
    cin >> k;

    cout << sol.characterReplacement(str, k);

    return 0;
}