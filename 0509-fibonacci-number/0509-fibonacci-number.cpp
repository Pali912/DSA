class Solution {
public:
    unordered_map<int,int>DP;
    int fun(int n){
        if(n==0 || n==1) return n;

        if(DP.find(n)!=DP.end()){
            return DP[n];
        }

        int a1=fun(n-1);
        int a2=fun(n-2);
        int ans=a1+a2;
        DP[n]=ans;
        return ans;
    }
    int fib(int n) {
        return fun(n);
    }
};