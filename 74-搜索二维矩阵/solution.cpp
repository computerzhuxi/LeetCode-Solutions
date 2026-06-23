class Solution {
public:
    int findRow(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, hight = m - 1;
        while (low <= hight) 
        {
            int mid = (low + hight) / 2;
            int x = matrix[mid][0], y = matrix[mid][n - 1];
            if (y < target) 
            {
                low = mid + 1;
            } 
            else if (x > target) 
            {
                hight = mid - 1;
            } 
            else 
            {
                return mid;
            }
        }
        return -1;
    }

    bool findColumn(vector<int>& row, int target) 
    {
        int n = row.size();
        int low = 0, hight = n - 1;
        while (low <= hight) 
        {
            int mid = (low + hight) / 2;
            int x = row[mid];
            if (x > target) 
            {
                hight = mid - 1;
            }
            else if (x < target) 
            {
                low = mid + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = findRow(matrix, target);
        if (row < 0)
            return false;
        return findColumn(matrix[row], target);
    }
};