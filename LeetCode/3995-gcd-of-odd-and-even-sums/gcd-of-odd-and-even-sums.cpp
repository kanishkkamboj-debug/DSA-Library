class Solution {
public:
    int GCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int result = GCD(n * n, n * (n + 1));
        return result;
    }
};