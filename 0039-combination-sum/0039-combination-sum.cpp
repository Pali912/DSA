class Solution {
public:

    void fun(vector<int>a,int n, int idx, vector<int>&diary,int sum, vector<vector<int>>&res,int tar){
        if(idx==n){
            if(sum==tar){
                res.push_back(diary);
                
            }
            return;
        }
        fun(a,n,idx+1,diary,sum,res,tar);

        if(a[idx]+sum<=tar){
            diary.push_back(a[idx]);
            sum+=a[idx];
            fun(a,n,idx,diary,sum,res,tar);
            diary.pop_back();
            sum-=a[idx];
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int> diary;
        fun(candidates,candidates.size(),0,diary,0,res,target);

        return res;
        
    }
};