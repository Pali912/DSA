class Solution {
public:

    void fun(string &s, int n, int idx, string &diary, vector<string>&res,unordered_map<char,string>&f){
        if(idx==n){
            res.push_back(diary);
            return;
        }
        string choice=f[s[idx]];
        for(int j=0;j<choice.size();j++){
            diary.push_back(choice[j]);
            fun(s,n,idx+1,diary,res,f);
            diary.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res; 

        unordered_map<char,string> f={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

        string diary="";
        fun(digits,digits.size(),0,diary,res,f);
        return res;
        
    }
};