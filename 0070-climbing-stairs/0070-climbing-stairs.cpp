class Solution {
public:
    unordered_map<int,int>DP;
    int fun(int i,int n){
        if(i==n)return 1;
        if(i>n)return 0;

        if(DP.find(i)!=DP.end()){
            return DP[i];
        }

        int a1=fun(i+1,n);
        int a2=fun(i+2,n);
        int ans=a1+a2;
        DP[i]=ans;
        return ans;
    }
    int climbStairs(int n) {
        return fun(0,n);
        
    }
};