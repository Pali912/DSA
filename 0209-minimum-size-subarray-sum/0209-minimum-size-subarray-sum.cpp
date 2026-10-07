class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int win=INT_MAX;
        int cs=0;
        int i=0,j=0;

        while(j<nums.size()){
            cs+=nums[j];
            j++;

            while(cs>=target){
                int cwin=j-i;

                win=min(win,cwin);
                cs-=nums[i];
                i++;
            }
        }
        if(win==INT_MAX){
            return 0;
        }
        return win;
        
    }
};