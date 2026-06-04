class Solution {
public:
    void dfs(const string& s, int i)
    {
        if(i == n)
        {
            ret.push_back(ans);
            return;
        }

        for(int j = i; j < n; ++j)
        {
            if(f[i][j])
            {
                ans.push_back(s.substr(i, j-i+1));
                dfs(s, j+1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) 
    {
        n = s.size();
        f.assign(n, vector<bool>(n,true));
        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = i + 1; j < n; ++j)
            {
                f[i][j] = f[i+1][j-1] && (s[i] == s[j]);
            }
        }
        dfs(s,0);
        return ret;
    }
private:
    vector<vector<string>> ret;
    int n;
    vector<string> ans;
    vector<vector<bool>>f;
};