class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.length(),m=s.length();
        vector<int> res;
        if(n>m) return res;

        vector<int> need(26,0), win(26,0);
        for(int i=0;i<n;i++){
            need[p[i]-'a']++;
            win[s[i]-'a']++;
        }
        if(need==win) res.push_back(0);

        for(int i=n;i<m;i++){
            win[s[i]-'a']++;
            win[s[i-n]-'a']--;
            if(need==win) res.push_back(i-n+1);
        }
        return res;

        
    }
};