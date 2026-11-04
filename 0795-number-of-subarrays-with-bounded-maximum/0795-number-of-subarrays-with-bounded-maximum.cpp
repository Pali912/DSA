class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int count = 0;
        int prev = 0;

        for (int num : nums) {
            if (num > right) {
                count = 0;
                prev = 0;
            }
            else if (num >= left) {
                count++;
                prev = count;
            }
            else {
                count++;
            }

            ans += prev;
        }

        return ans;
    }
};