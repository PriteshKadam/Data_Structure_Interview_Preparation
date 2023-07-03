// https://leetcode.com/problems/set-matrix-zeroes/description/
// Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// In first iteration over the matrix.
// Use 0th row to mark if a column is 0
// USe 0th column to mark if a row is 0.
// For cell [0][0] : USe it for marking 0th column and use a separate variable to mark if 0th row is 0.
//  
// Iterate over 0th column(Excluding cell[0][0]) to set 0 rows.
// Iterate over 0th row to set o columns
// Check cell[0][0] to set oth row.

class Solution {
public:
    
    
    void setZeroes(vector<vector<int>>& matrix) {
        int row0 = 1; // for 0th row 

        // matrix[0][j] : j = 0 to n : 0th row = specifies whether jth column should be 0
        // matrix[i][0]: i : 1 to m : 0th Column = specifies whether ith row should be 0

        for(int row = 0; row < matrix.size(); row ++)
        {
            for(int col = 0; col < matrix[row].size(); col++)
            {
                if(matrix[row][col] == 0)
                {
                    matrix[0][col] = 0;
                    if(row == 0)
                    {
                        row0 = 0; 
                    }
                    else
                    {
                        matrix[row][0] = 0;
                    }
                }
            }
        } 

        // MArk rows

        for(int row = 1; row < matrix.size(); row ++)
        {
            if(matrix[row][0] == 0)
            {
                for(int col = 0; col < matrix[row].size(); col++)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        // MArk Columns
        for(int col = 0; col < matrix[0].size(); col ++)
        {
            if(matrix[0][col] == 0)
            {
                for(int row = 0; row < matrix.size(); row++)
                {
                    matrix[row][col] = 0;
                }
            }
        }
        
        // MArk 0th row
        if(row0 == 0)
        {
            for(int col = 0; col < matrix[0].size(); col++)
            {
                matrix[0][col] = 0;
            }            
        }        
    }
};