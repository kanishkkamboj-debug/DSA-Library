class Solution {
public:
    int maxDepth(string s) {
    stack<int > st;
    int count=0;
    int maxi=0;
    for(auto val :s){
        if(val=='('){
            count++;
            maxi=max(count,maxi);
        }if(val==')'){
            count--;
        }
    }
    return maxi; 
    }
};