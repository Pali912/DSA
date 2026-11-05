class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0) return 0;

        sort(nums.begin(), nums.end());

        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int target = nums[i] + k;

            if(binary_search(nums.begin() + i + 1, nums.end(), target)) {
                count++;
            }
        }

        return count;
    }
};