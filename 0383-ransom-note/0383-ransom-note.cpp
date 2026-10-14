class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>r;
        unordered_map<char,int>m;
        int n=ransomNote.size();
        int p=magazine.size();

        for(int i=0;i<n;i++){
            r[ransomNote[i]]++;
        }
        for(int i=0;i<p;i++){
            m[magazine[i]]++;
        }

        for(int i=0;i<n;i++){
            if(r[ransomNote[i]]>m[ransomNote[i]]){
                return false;
            }
        }
        return true;
        
    }
};