class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n)
        {
            if(n%4 == 0 || n%4 == 3)
                return false;
            n /=2;
        }
        return true;
    }
};