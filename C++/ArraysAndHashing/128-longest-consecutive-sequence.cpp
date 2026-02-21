/*
Given an unsorted array of integers nums, return the
length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/

#include <bits/stdc++.h>

using namespace std;

/*
Como pense en resolver esto es primero convertir todo a un hashset, para evitar duplicados,
luego checar si existe x - 1, si esto es verdad es porque x no es el inicio de la secuencia,
entonces debemos llegar a un numero que no tenga x - 1, si llegamos al inicio de una secuencia,
ahora si contamos los elementos consecutivos.
*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int res = 0;

        if (nums.empty())
            return res;

        unordered_set<int> nums_set(nums.begin(), nums.end());

        for (int x : nums_set)
        {
            int LENGTH = 1;
            if (!nums_set.count(x - 1))
            {
                int y = x;
                LENGTH = 1;
                while (nums_set.count(y + 1))
                {
                    LENGTH++;
                    y++;
                }
            }
            res = max(res, LENGTH);
        }
        return res;
    }
};

int main()
{

    Solution sol;

    // vector<int> test = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    vector<int> test = {100, 4, 200, 1, 3, 2};

    int LENGTH = sol.longestConsecutive(test);

    cout << LENGTH << endl;

    return 0;
}