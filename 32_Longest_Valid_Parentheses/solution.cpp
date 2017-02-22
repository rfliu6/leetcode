class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i=0; i<s.size(); i++){
            int pre = stk.top();
            if(pre != -1 && s[i] == ')' && s[pre] == '('){
                stk.pop();
                result = max(result, i-stk.top());
            }else{
                stk.push(i);
            }
        }
        return result;
    }
};
