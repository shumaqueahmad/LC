class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;

        int n = s.size();
        int count = 0;// count is resp to check if it is an opening or closing bracket
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (count > 0)
                    ans += s[i];

                count++;// for opening pehle counnt check the it is added kunki if pehle count ++ then first bracket
                //will also be added
            } else if (s[i] == ')') {
                count--;
                if (count > 0) {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};