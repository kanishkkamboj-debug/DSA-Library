class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for (auto val : word) {
            freq[val - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int count = 0;
        for (int i = 0; i < word.size(); i++) {
            count += freq[i] * (1 + (i / 8));
        }
        return count;
    }
};