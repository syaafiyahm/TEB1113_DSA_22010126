/*
id: 22010126
name: muni
group: g3
lab: L2
*/

//C++ program to perform spiral order 
// traversal of a matrix
#include <iostream>
#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    vector<vector<bool> > vis(m, vector<bool>(n, false));

    // Arrays to represent the changes in row and column indices: 
  	// move right(0, +1), move down(+1, 0), 
  	// move left(0, -1), move  up(-1, 0)
  
    // Change in row index for each direction
    vector<int> dr = { 0, 1, 0, -1 };

    // Change in column index for each direction
    vector<int> dc = { 1, 0, -1, 0 };

    // Initial position in the matrix
    int r = 0, c = 0;

    // Initial direction index (0 corresponds to 'right')
    int idx = 0;

    for (int i = 0; i < m * n; ++i) {
        res.push_back(mat[r][c]);
        vis[r][c] = true;

        // Calculate the next cell coordinates based on
        // current direction
        int newR = r + dr[idx];
        int newC = c + dc[idx];

        // Check if the next cell is within bounds and not
        // visited
        if (0 <= newR && newR < m && 0 <= newC && newC < n
            && !vis[newR][newC]) {

            // Move to the next row
            r = newR;

            // Move to the next column
            c = newC;
        }
        else {

            // Change direction (turn clockwise)
            idx = (idx + 1) % 4;

            // Move to the next row according to new
            // direction
            r += dr[idx];

            // Move to the next column according to new
            // direction
            c += dc[idx];
        }
    }
  
    return res;
}


int main() {
    vector<vector<int>> mat = { { 1, 2, 3, 4 },
                                    { 5, 6, 7, 8 },
                                    { 9, 10, 11, 12 },
                                    { 13, 14, 15, 16 } };

    vector<int> res = spirallyTraverse(mat);

    for (int num : res) {
        cout << num << " ";
    }
    return 0;
}