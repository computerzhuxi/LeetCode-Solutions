class Solution {
public:
    void solve(int n, int row, int columns, int diagonals1, int diagonals2)
    {
        if(row == n)
        {
            generateBoard(n);
        }
        else
        {
            int availblePositions = ((1<<n) -1) & (~(columns|diagonals1|diagonals2));
            int index = 0;
            int position = 1;
            while(availblePositions!=0)
            {
                if((availblePositions & 1) == 1)
                {
                    visits[row] = index;
                    solve(n, row+1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
                    visits[row] = -1;

                }
                availblePositions = availblePositions>>1;
                position = position << 1;
                ++index;
            }
        }
    }

    void generateBoard(int n)
    {
        auto board = vector<string>();
        for(int i = 0; i < n; i++)
        {
            string row = string(n,'.');
            row[visits[i]] = 'Q';
            board.push_back(row);
        }
        solution.push_back(board);
    }

    vector<vector<string>> solveNQueens(int n) {
        visits = vector<int>(n,-1);
        solve(n,0,0,0,0);
        return solution;
    }

private:
    vector<vector<string>> solution;
    vector<int> visits;
};