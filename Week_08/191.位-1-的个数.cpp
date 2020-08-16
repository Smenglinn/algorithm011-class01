/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return n ? 1 + hammingWeight(n & (n - 1)) : 0;
    }
};
// @lc code=end

