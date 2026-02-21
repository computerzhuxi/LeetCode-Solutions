class Solution {
public:
    // 二进制中1的个数
    int hammingWeight(int num)
    {
        int count = 0;
        while(num)
        {
            num &= num -1;
            count++;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++)
        {
            if((1<<hammingWeight(i)) & 665772)
                cnt++;
        }
        return cnt;
    }
};