class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // 要想返回 true ，至少需要有 2^k 个长度为 k 的字符串
        if (s.size() < (1 << k) + k - 1)
        {
            return false;
        }

        unordered_set<string> exists;
        for(int i = 0; i + k <= s.size(); i++)
        {
            // 这里使用 move 是因为 substr 返回的是一个临时的变量。为了避免不必要的拷贝，使用 move 来转移使用权。
            // 但是对于 substr 产生的临时变量，编译器会自动将其视为右值，insert 能调用移动插入，不需要 move，加入 move 不会改变其行为，不过为了明确意图，也可以加，没有坏处
            // 在使用非临时对象（如一个左值）时，我们使用 move 来转移所有权避免不必要的拷贝
            exists.insert(move(s.substr(i, k)));
        }
        return exists.size() == (1 << k);
    }
};