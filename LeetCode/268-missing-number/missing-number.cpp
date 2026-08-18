class Solution {
public:
    // bruteforce 
    int missingNumber(vector<int>& nums) {
    int maxi=0;
    int sum=0;
    int n=nums.size();
    for(auto val:nums){
        maxi = max(maxi,val);
        sum+=val;
    }   
    int find= (n*(n+1))/2;

    return find-sum;
    }
};