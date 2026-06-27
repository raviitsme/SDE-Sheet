#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Queue to store coordinates of rotten oranges: {row, col}
        queue<pair<int, int>> q;
        int freshOranges = 0;
        
        // Step 1: Initialize the queue with all initial rotten oranges
        // and count the total number of fresh oranges.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }
        
        // If there are no fresh oranges to begin with, 0 minutes are needed.
        if (freshOranges == 0) return 0;
        
        int minutes = 0;
        // Direction vectors for 4-directional movement (Up, Down, Left, Right)
        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};
        
        // Step 2: Begin BFS simulation
        while (!q.empty()) {
            int size = q.size();
            bool rottedAnyThisMinute = false;
            
            // Process all rotten oranges at the current minute level
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                // Check all 4 neighbors
                for (int d = 0; d < 4; d++) {
                    int nRow = r + dRow[d];
                    int nCol = c + dCol[d];
                    
                    // If neighbor is within bounds and is a fresh orange
                    if (nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1) {
                        grid[nRow][nCol] = 2; // Turn it rotten
                        freshOranges--;       // Decrement fresh count
                        q.push({nRow, nCol}); // Push to queue for next minute
                        rottedAnyThisMinute = true;
                    }
                }
            }
            
            // If we managed to rot at least one fresh orange, increment time
            if (rottedAnyThisMinute) {
                minutes++;
            }
        }
        
        // Step 3: If fresh oranges remain, return -1; otherwise, return time elapsed
        return freshOranges == 0 ? minutes : -1;
    }
};

int main() {
    Solution solver;
    
    // Example grid: 
    // 2 (rotten)  1 (fresh)   1 (fresh)
    // 1 (fresh)   1 (fresh)   0 (empty)
    // 0 (empty)   1 (fresh)   1 (fresh)
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    int result = solver.orangesRotting(grid);
    
    cout << "Minimum minutes to rot all oranges: " << result << endl;
    // Expected output: 4
    
    return 0;
}