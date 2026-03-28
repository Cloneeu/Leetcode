/*
Given an m x n grid of characters board and a string word,
return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
where adjacent cells are horizontally or vertically neighboring.
The same letter cell may not be used more than once.

Example 1:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true

Example 2:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true

Example 3:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false

Constraints:
    -- m == board.length
    -- n = board[i].length
    -- 1 <= m, n <= 6
    -- 1 <= word.length <= 15
    -- board and word consists of only lowercase and uppercase English letters.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // Variables para almacenar dimensiones de la matriz
    int ROWS, COLS;

    // Matriz para rastrear celdas visitadas durante la búsqueda
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>> &board, string word)
    {
        // Dimensiones de la matriz
        ROWS = board.size();
        COLS = board[0].size();

        // Crear matriz de visitados, inicialmente todos falso (no visitados)
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        // PASO 1: Intentar comenzar la búsqueda desde cada celda de la matriz
        // Si la palabra comienza con el carácter en esa celda, se hace DFS desde ahí
        for (int r = 0; r < ROWS; r++)
        {
            for (int c = 0; c < COLS; c++)
            {
                // Iniciar DFS desde celda (r, c) buscando el carácter 0 (primero) de la palabra
                if (dfs(board, word, r, c, 0))
                {
                    return true; // Palabra encontrada
                }
            }
        }

        // Si ningún punto de inicio funcionó, la palabra no existe
        return false;
    }

    // Función DFS: busca recursivamente en profundidad desde una posición específica
    bool dfs(vector<vector<char>> &board, string word, int r, int c, int i)
    {
        // CASO BASE: Se encontraron todos los caracteres de la palabra
        if (i == word.length())
        {
            return true; // Palabra completada exitosamente
        }

        // VALIDACIONES: Verificar si la posición es válida
        // 1. r < 0 || c < 0: posición fuera del límite inferior
        // 2. r >= ROWS || c >= COLS: posición fuera del límite superior
        // 3. board[r][c] != word[i]: el carácter no coincide con el buscado
        // 4. visited[r][c]: la celda ya fue visitada en esta ruta (previene ciclos)
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i] || visited[r][c])
        {
            return false; // Ruta inválida, no continuar por aquí
        }

        // PASO 1: Marcar la celda actual como visitada en esta ruta
        visited[r][c] = true;

        // PASO 2: Explorar las 4 direcciones adyacentes (arriba, abajo, derecha, izquierda)
        // Se busca el siguiente carácter (i + 1) en las celdas adyacentes
        bool res = dfs(board, word, r + 1, c, i + 1) || // Bajar (siguiente fila)
                   dfs(board, word, r - 1, c, i + 1) || // Subir (fila anterior)
                   dfs(board, word, r, c + 1, i + 1) || // Derecha (siguiente columna)
                   dfs(board, word, r, c - 1, i + 1);   // Izquierda (columna anterior)

        // PASO 3: BACKTRACKING - Desmarcar la celda como visitada
        // Permite que otras rutas puedan usar esta celda
        // Esto es crucial para explorar todas las posibles rutas de la palabra
        visited[r][c] = false;

        return res; // Retornar si se encontró la palabra en alguna dirección
    }
};