class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> occ;
        int left = 0, right = 0;
        int ans = 0;
        while (right < s.size())
        {
            if (occ.find(s[right]) != occ.end())
            {
                occ.erase(s[left]);
                left++;
            }
            else
            {
                occ.insert(s[right]);
                right++;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};