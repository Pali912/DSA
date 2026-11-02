class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;

        int level = 0;
        int temp = label;

        while (temp > 0) {
            level++;
            temp /= 2;
        }

        while (level > 0) {
            ans.push_back(label);

            int start = 1 << (level - 1);
            int end = (1 << level) - 1;

            label = (start + end - label) / 2;

            level--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};