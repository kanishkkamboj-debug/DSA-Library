class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (auto val : word) {
            freq[val - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int total = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                break;
            total += freq[i] * (1 + (i / 8));
        }
        return total;
    }
};