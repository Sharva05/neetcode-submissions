class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0, down = matrix.size() - 1, l = 0, r = matrix[0].size() - 1, mid, mid2;
        while(up <= down) {
            mid = up + (down - up) / 2;
            if(target <= matrix[mid][r] && (mid == 0 || target > matrix[mid -1][r]))
                break;
            else if(target < matrix[mid][r]) down = mid - 1;
            else up = mid + 1;
        }
        while(l <= r) {
            mid2 = l + (r - l) / 2;
            if(matrix[mid][mid2] == target) return true;
            else if(target < matrix[mid][mid2]) r =  mid2 - 1;
            else l = mid2 + 1;
        }
        return false;
    }
};