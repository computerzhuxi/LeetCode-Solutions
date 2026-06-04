class Solution {
public:
    bool check(const vector<vector<char>>& board, vector<vector<bool>>& visited, const string&word, int i, int j, int k)
    {
        if(board[i][j] != word[k])
        {
            return false;
        }
        if(k == word.size() - 1)
        {
            return true;
        }
        visited[i][j] = true;
        const vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        for(const auto& dir:directions)
        {
            int newi = i + dir.first, newj = j + dir.second;
            if(newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size())
            {
                if(!visited[newi][newj])
                {
                    bool flag = check(board, visited, word, newi, newj, k+1);
                    if(flag)
                    {
                        return true;
                    }
                }
            }
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<bool>> visited(h,vector<bool>(w));
        for(int i = 0; i < h; ++i)
        {
            for(int j = 0; j < w; ++j)
            {
                bool flag = check(board, visited, word, i, j, 0);
                if(flag)
                    return true;
            }
        }
        return false;
    }
};