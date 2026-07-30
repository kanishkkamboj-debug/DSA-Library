class Solution {
public:
    int minimumPushes(string word) {
        int count = 0;
        for (int i = 0; i < word.size(); i++) count += (1 + (i / 8));
        return count;
    }
};