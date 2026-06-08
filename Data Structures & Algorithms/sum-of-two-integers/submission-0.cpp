class Solution {
public:
    int getSum(int a, int b) {
        // 1
        // 1
        //10 
         while (b != 0) {
            int carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
