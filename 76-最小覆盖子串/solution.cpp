class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> ori(128), cnt(128);
        int left = 0, right = 0;
        int tSize = 0;
        for (const auto &c : t)
        {
            if (ori[c - 'A'] == 0)
            {
                tSize++;
            }
            ori[c - 'A']++;
        }
        while (right < s.size() && tSize > 0)
        {
            int n = s[right++] - 'A';
            cnt[n]++;
            if (cnt[n] == ori[n])
            {
                tSize--;
            }
        }

        int len = right - left, ansL = left;
        if (tSize != 0)
        {
            return string();
        }
        while (right < s.size() || tSize == 0)
        {
            while (tSize && right < s.size())
            {
                int end = s[right] - 'A';
                cnt[end]++;
                right++;
                if (cnt[end] == ori[end])
                {
                    tSize--;
                }
            }

            while (left < right && tSize == 0)
            {
                int begin = s[left] - 'A';
                if (len > right - left)
                {
                    len = right - left;
                    ansL = left;
                }
                cnt[begin]--;
                left++;
                if (cnt[begin] < ori[begin])
                {
                    tSize++;
                }
            }
        }
        return s.substr(ansL, len);
    }
};