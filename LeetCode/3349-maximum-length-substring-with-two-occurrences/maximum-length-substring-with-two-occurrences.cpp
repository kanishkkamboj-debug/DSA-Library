class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi = 0;
        vector<int> count(26, 0);
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++;
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};