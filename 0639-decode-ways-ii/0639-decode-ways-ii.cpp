class Solution {
public:
    int numDecodings(string s) {
        long long mod = 1000000007;

        long long prev2 = 1;
        long long prev1 = (s[0] == '*') ? 9 : (s[0] == '0' ? 0 : 1);

        for (int i = 1; i < s.size(); i++) {
            long long one = 0;
            long long two = 0;

            if (s[i] == '*') {
                one = 9 * prev1;
            }
            else if (s[i] != '0') {
                one = prev1;
            }

            if (s[i - 1] == '*' && s[i] == '*') {
                two = 15 * prev2;
            }
            else if (s[i - 1] == '*') {
                if (s[i] >= '0' && s[i] <= '6') {
                    two = 2 * prev2;
                }
                else {
                    two = prev2;
                }
            }
            else if (s[i] == '*') {
                if (s[i - 1] == '1') {
                    two = 9 * prev2;
                }
                else if (s[i - 1] == '2') {
                    two = 6 * prev2;
                }
            }
            else {
                int num = (s[i - 1] - '0') * 10 + (s[i] - '0');

                if (num >= 10 && num <= 26) {
                    two = prev2;
                }
            }

            long long curr = (one + two) % mod;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};