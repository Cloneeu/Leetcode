#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0, right = 1; // Pointers
        
        int maxProfit = 0;

        while (right < prices.size())
        {
            if (prices[left] > prices[right])
            {
                left = right;
            }
            else
            {
                int profit = prices[right] - prices[left]; 
                maxProfit = max(profit, maxProfit);
            }
            right++;
        }

        return maxProfit;
    }
};

int main()
{
    Solution sol;

    vector<int> test = {7, 6, 4, 3, 1};

    cout << sol.maxProfit(test);

    return 0;
}