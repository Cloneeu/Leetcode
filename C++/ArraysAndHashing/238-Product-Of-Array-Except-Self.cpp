/*
Given an integer array nums, return an array answer such that answer[i]
is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int LENGHT = nums.size();

        vector<int> res(LENGHT, 1); // Resultado


        for (int i = 1; i < LENGHT; i++)
        {
            res[i] = nums[i - 1] * res[i - 1];
        }

        int post = 1;

        for (int i = LENGHT - 1; i >=0; i--)
        {
            res[i] *= post;
            post *= nums[i]; 
        }

        return res;
    }
};

int main()
{

    Solution sol;

    vector<int> test = {1, 2, 3, 4, 5};

    auto resultado = sol.productExceptSelf(test);

    for (int x: resultado)
    {
        cout << x << ' ';
    }

    return 0;
}