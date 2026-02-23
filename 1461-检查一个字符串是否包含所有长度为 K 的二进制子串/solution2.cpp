class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // 要想返回 true ，至少需要有 2^k 个长度为 k 的字符串
        if (s.size() < (1 << k) + k - 1)
        {
            return false;
        }
        // 将字符串s.substr(0, k)转换为二进制，并输出为int
        int num = stoi(s.substr(0, k), nullptr, 2);
        unordered_set<int> exists = {num};

        for(int i =1; i + k <= s.size(); i++)
        {
            num = (num - ((s[i-1] - '0') * 1 << (k-1))) * 2 + (s[i + k -1] - '0');
            exists.insert(num);
        }
        return exists.size() == (1 << k);
    }
};