class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];

        }
        int left=0;
        int right=k;
        int maxsum=sum;
        while(right<n){
            sum-=nums[left];
            left++;

            sum+=nums[right];
            right++;

            maxsum=max(maxsum,sum);
        }
        return (double) maxsum/k;
        
    }
};