class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0, den = 1;
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;

            if (expression[i] == '-') {
                sign = -1;
                i++;
            }
            else if (expression[i] == '+') {
                i++;
            }

            int a = 0;
            while (i < n && isdigit(expression[i])) {
                a = a * 10 + (expression[i] - '0');
                i++;
            }

            i++; // skip '/'

            int b = 0;
            while (i < n && isdigit(expression[i])) {
                b = b * 10 + (expression[i] - '0');
                i++;
            }

            a *= sign;

            num = num * b + a * den;
            den = den * b;

            int g = gcd(abs(num), den);
            num /= g;
            den /= g;
        }

        return to_string(num) + "/" + to_string(den);
    }
};