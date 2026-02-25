class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
    string current = "";

    function<void(int,int)> backtrack = [&](int open, int close) {
        
        // Base case
        if(current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if possible
        if(open < n) {
            current.push_back('(');
            backtrack(open + 1, close);
            current.pop_back();  // backtrack
        }

        // Add ')' if valid
        if(close < open) {
            current.push_back(')');
            backtrack(open, close + 1);
            current.pop_back();  // backtrack
        }
    };

    backtrack(0, 0);
    return result;
    }
};