class Solution {
public:
    int bitwiseComplement(int n) {
        // edge case 
        if (n == 0)
            return 1;
        int mask = 0;
        int temp = n;
        // to find mask 
        while (temp > 0) {
            mask = (mask << 1) | 1;
            temp = temp >> 1;
        }
        // to flip al in its lenght
        return n ^ mask;
    }
};