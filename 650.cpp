class Solution {
public:
    int minSteps(int n) {
        vector<int> f(n + 1);
        for (int i = 2; i <= n; ++i) {
            f[i] = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                if (i % j == 0) {
                    f[i] = min(f[i], f[j] + i / j);
                    f[i] = min(f[i], f[i / j] + j);
                }
            }
        }
        return f[n];
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/2-keys-keyboard/solution/zhi-you-liang-ge-jian-de-jian-pan-by-lee-ussa/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。