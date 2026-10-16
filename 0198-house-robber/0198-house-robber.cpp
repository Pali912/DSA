class Solution {
public:
    int fun(vector<int>&a, int n,int i, int free, vector<vector<int>> &DP){
        if(i==n) return 0;
        if(DP[i][free]!=-1){
            return DP[i][free];
        }
        if(free==0){

            return DP[i][free]=fun(a,n,i+1,1,DP);
        }
        int c1=a[i]+fun(a,n,i+1,0,DP);
        int c2=fun(a,n,i+1,1,DP);

        return DP[i][free]=max(c1,c2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> DP(n,vector<int>(2,-1));
        return fun(nums,n,0,1,DP);
        
    }
};