class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = false;
        bool col0 = false;
        
        // Check if first row has any zeros
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }
        
        // Check if first column has any zeros
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        
        // Use first row and column as markers for the rest of the matrix
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // Mark row
                    matrix[0][j] = 0;  // Mark column
                }
            }
        }
        
        // Set zeros for the inner matrix based on markers
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // Handle first row
        if(row0) {
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        
        // Handle first column
        if(col0) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};