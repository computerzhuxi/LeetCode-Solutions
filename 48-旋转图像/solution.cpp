class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        int left = 0, right = n, top = 0, bottom = n;
        while(left < right && top < bottom)
        {
            for(int i = left; i < right; i++)
            {
                int temp = matrix[top][i];
                matrix[top][i] = matrix[n - i][left];
                matrix[n - i][left] = matrix[bottom][n - i];
                matrix[bottom][n - i] = matrix[i][right];
                matrix[i][right] = temp;
            }
            top++;
            bottom--;
            left++;
            right--;
        }
    }
};