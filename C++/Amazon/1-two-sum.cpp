/*
Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you
may not use the same element twice.

You can return the answer in any order.

Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]

Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]

Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;

        // Iteramos sobre cada elemento del array
        for (int i = 0; i < nums.size(); i++)
        {
            // Calculamos el complemento: el número que necesitamos encontrar
            // para sumar target (complement + nums[i] = target)
            int complement = target - nums[i];

            // Verificamos si el complemento ya existe en el mapa
            // Si existe, encontramos la pareja que suma target
            if (map.find(complement) != map.end())
            {
                // Retornamos los índices de los dos números que suman target
                return {map[complement], i};
            }

            // Si el complemento no existe, almacenamos el número actual
            // en el mapa con su índice para futuras búsquedas
            map[nums[i]] = i;
        }

        // Si no encontramos dos números que sumen target, retornamos un vector vacío
        return {};
    }
};