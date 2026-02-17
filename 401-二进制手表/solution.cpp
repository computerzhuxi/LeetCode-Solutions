class Solution {
public:
    // 输入一个数返回转成二进制后的1的个数
    int num(int n)
    {
        int m = 0;
        while(n)
        {
            m+=n%2;
            n/=2;
        }
        return m;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int h = 0; h < 12; h++)
        {
            for(int min = 0; min < 60; min++)
            {
                if(num(h) + num(min) == turnedOn)
                    ans.push_back(to_string(h) + ":" + (min < 10 ? "0" : "")+to_string(min));
            }
        }
        return ans;
    }
};