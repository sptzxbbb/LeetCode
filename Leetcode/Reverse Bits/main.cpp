class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
         uint32_t ans = 0, count = 32;
    while (count--) {
      ans = ans * 2 + n % 2;
      n /= 2;
    }
    return ans;
    }
};
