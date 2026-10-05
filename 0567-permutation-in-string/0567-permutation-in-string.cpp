class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length(),m=s2.length();

        if(n>m) return false;

        vector<int> need(26,0), win(26,0);
        for(int i=0;i<n;i++){
            need[s1[i]-'a']++;
            win[s2[i]-'a']++;
        }

        if(need==win) return true;

        for(int i=n;i<m;i++){
            win[s2[i]-'a']++;
            win[s2[i-n]-'a']--;
            if(need==win) return true;

        }
        return false;
        
    }
};