class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s="balloon";
        unordered_map<char,int>need;
        unordered_map<char,int>have;

        for(int i=0;i<s.size();i++){
            need[s[i]]++;
        }
        for(int i=0;i<text.size();i++){
            have[text[i]]++;
        }

        int ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            ans=min(ans,have[s[i]]/need[s[i]]);
        }

        return ans;

        
    }
};