/*
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.

Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

Example 2:
    Input: nums = [1], k = 1
    Output: [1]

Example 3:
    Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
    Output: [1,2]

Constraints:
    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n),
where n is the array's size.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // Crear un bucket donde el índice representa la frecuencia
        // y el valor es un vector de números con esa frecuencia
        vector<vector<int>> bucket(nums.size() + 1);
        
        // Mapa para contar la frecuencia de cada número
        unordered_map<int, int> freqs;

        // Paso 1: Contar la frecuencia de cada número en el array
        for (int num : nums)
        {
            freqs[num]++;
        }

        // Paso 2: Agrupar los números en buckets según su frecuencia
        // bucket[freq] contiene todos los números que aparecen 'freq' veces
        for (auto &freq : freqs)
        {
            bucket[freq.second].push_back(freq.first);
        }

        // Paso 3: Recolectar los k elementos más frecuentes
        // Iteramos desde la frecuencia más alta hacia abajo
        vector<int> res;

        // Recorrer desde la frecuencia mayor (final del bucket) hasta la menor
        for (int i = bucket.size() - 1; i > 0; i--)
        {
            // Agregar todos los números que tienen frecuencia i
            for (int num: bucket[i])
            {
                res.push_back(num);
                
                // Detener cuando hayamos recolectado k elementos
                if (res.size() == k)
                {
                    return res;
                }
            }
        }

        return res;
    }
};