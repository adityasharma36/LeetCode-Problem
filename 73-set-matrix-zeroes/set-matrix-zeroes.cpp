#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Use a boolean to track if the first column needs to be zeroed
        bool col0 = true;
        
        // First pass: Use the first row and column as markers
        for (int i = 0; i < n; ++i) {
            // Handle the case where an element in the first column is 0
            if (matrix[i][0] == 0) {
                col0 = false;
            }
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    // Mark the row and column
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Second pass: Use markers to set the inner matrix to zero
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 1; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Final pass: Zero out the first row and/or column if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; ++j) {
                matrix[0][j] = 0;
            }
        }
        if (!col0) {
            for (int i = 0; i < n; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};