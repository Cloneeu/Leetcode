/*
You are given an m x n grid where each cell can have one of three values:

- 0 representing an empty cell,
- 1 representing a fresh orange, or
- 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

-> Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
    Input: grid =  [[2,1,1],
                    [1,1,0],
                    [0,1,1]]
    Output: 4

Example 2:
    Input: grid =  [[2,1,1],
                    [0,1,1],
                    [1,0,1]]
    Output: -1
    Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
    Input: grid = [[0,2]]
    Output: 0
    Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:
    -- m == grid.length
    -- n == grid[i].length
    -- 1 <= m, n <= 10
    -- grid[i][j] is 0, 1, or 2.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Cola para almacenar las posiciones de naranjas podridas que necesitan propagar el púdrimiento
        queue<pair<int, int>> rotten_oranges;

        // Contador de minutos transcurridos
        int time = 0;

        // Contador de naranjas frescas restantes
        int fresh_oranges = 0;

        // PASO 1: Recorrer la matriz y contar naranjas frescas e inicializar cola de podridas
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // Incrementar contador si hay una naranja fresca
                if (grid[i][j] == 1)
                    fresh_oranges++;

                // Agregar a la cola si hay una naranja podrida (punto de inicio para BFS)
                if (grid[i][j] == 2)
                    rotten_oranges.push({i, j});
            }
        }

        // PASO 2: Definir las 4 direcciones adyacentes (arriba, abajo, derecha, izquierda)
        vector<pair<int, int>> dirs = {
            {-1, 0}, // Arriba (decrementar fila)
            {1, 0},  // Abajo (incrementar fila)
            {0, 1},  // Derecha (incrementar columna)
            {0, -1}  // Izquierda (decrementar columna)
        };

        // PASO 3: Procesar el BFS nivel por nivel (cada nivel = 1 minuto)
        while (fresh_oranges > 0 && !rotten_oranges.empty())
        {
            // Guardar el número de naranjas podridas actuales (para procesar un nivel completo)
            // Esto es crucial para simular que todas se pudren simultáneamente cada minuto
            int lenght = rotten_oranges.size();

            // Procesar todas las naranjas podridas del nivel actual
            for (int i = 0; i < lenght; i++)
            {
                // Obtener la naranja podrida actual
                auto curr = rotten_oranges.front();
                rotten_oranges.pop();

                int r = curr.first;  // Fila actual
                int c = curr.second; // Columna actual

                // Revisar todas las 4 direcciones adyacentes
                for (const auto &dir : dirs)
                {
                    int row = r + dir.first;  // Nueva fila
                    int col = c + dir.second; // Nueva columna

                    // Validar que la posición sea válida y contenga una naranja fresca
                    if (row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1)
                    {
                        // Cambiar la naranja fresca a podrida
                        grid[row][col] = 2;

                        // Agregar la nueva naranja podrida a la cola para procesar en el siguiente minuto
                        rotten_oranges.push({row, col});

                        // Decrementar el contador de naranjas frescas
                        fresh_oranges--;
                    }
                }
            }

            // Incrementar el tiempo después de procesar un nivel completo
            time++;
        }

        // Retornar el tiempo si todas se pudrieron, o -1 si quedaron frescas
        return fresh_oranges == 0 ? time : -1;
    }
};