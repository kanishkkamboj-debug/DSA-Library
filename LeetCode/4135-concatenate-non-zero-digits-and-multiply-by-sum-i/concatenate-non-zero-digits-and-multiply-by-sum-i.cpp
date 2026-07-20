class Solution {
public:
    long long sumAndMultiply(int n) {
        string num = to_string(n);
        string ans = "";
        int sum = 0;
        for (auto val : num) {
            if (val != '0') {
                ans.push_back(val);
                sum += (int)(val - '0');
            }
        }
        if( ans.empty()){
            return 0;
        }
        return stoll(ans) * sum;
    }
};