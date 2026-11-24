
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {

                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> l = diffWaysToCompute(left);
                vector<int> r = diffWaysToCompute(right);

                for (int a : l) {
                    for (int b : r) {

                        if (ch == '+')
                            ans.push_back(a + b);

                        else if (ch == '-')
                            ans.push_back(a - b);

                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // If there is no operator, return the number itself
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        return ans;
    }
};
