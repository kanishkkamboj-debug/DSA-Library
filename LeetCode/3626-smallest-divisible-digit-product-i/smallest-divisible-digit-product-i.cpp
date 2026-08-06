class Solution {
public:
    int sumof(int k) {
        int sum = 1;
        while (k > 0) {
            sum *= k % 10;
            k /= 10;
        }
        return sum;
    }
    int smallestNumber(int n, int t) {
        int j = n;
        while (true) {
            if (sumof(j) % t == 0) {
                break;
            }
            j++;
        }
        return j;
    }
};