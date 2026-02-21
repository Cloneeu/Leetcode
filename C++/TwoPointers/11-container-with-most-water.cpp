#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;
        int length = height.size();

        int left = 0, right = length - 1; // Pointers

        while (left < right)
        {
            int max_current = ((right - left) * min(height[left], height[right]));

            res = max(max_current, res);

            if (height[left] > height[right])
                right--;
            else 
                left++;
        }
        return res;
    }
};

int main()
{
    vector<int> heights = {2,5,5,2};

    Solution sol;

    cout << sol.maxArea(heights);

    return 0;
}