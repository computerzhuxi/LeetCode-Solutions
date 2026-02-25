class Solution {
public:
    int get(int x)
    {
        int res = 0;
        while(x)
        {
            if(x%2 == 1)
                res++;
            x/=2;
        }
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> bit(10001,0);
        for(auto x : arr)
        {
            bit[x] = get(x);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y)
        {
            if(bit[x] < bit[y])
                return true;
            if (bit[x] > bit[y]) {
                return false;
            }
            // x和y在原数组里面是没有先后关系的，因此但bit[x] == bit[y] 时还需要比较x和y 的大小
            return x < y;
        });
        return arr;
    }
};