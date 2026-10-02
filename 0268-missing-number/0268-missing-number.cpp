class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n + 1);

        for(int i = 0; i <= n; i++){
            ans[i] = i;
        }

        for(int i = 0; i <= n; i++){
            bool found = false;

            for(int j = 0; j < n; j++){
                if(ans[i] == nums[j]){
                    found = true;
                    break;
                }
            }

            if(found == false){
                return ans[i];
            }
        }

        return 0;
    }
};