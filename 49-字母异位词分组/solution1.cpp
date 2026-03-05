class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            // 当value为容器时，使用emplace_back()方法添加元素,如果不是容器则使用=来赋值
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};