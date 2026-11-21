class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = 0, neg = 0;
        int k = 0;

        while (target > 0) {
            int cur = target % x;
            target /= x;

            if (k == 0) {
                pos = cur * 2;
                neg = (x - cur) * 2;
            } 
            else {
                int pos2 = min(pos + cur * k,
                               neg + (cur + 1) * k);

                int neg2 = min(pos + (x - cur) * k,
                               neg + (x - cur - 1) * k);

                pos = pos2;
                neg = neg2;
            }

            k++;
        }

        return min(pos, neg + k) - 1;
    }
};