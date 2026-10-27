class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=haystack.size();
        int n=needle.size();
        for(int i=0;i<h;i++){
            for(int j=0;j<n;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(j==n-1) return i;
            }
        }
        return -1;
        
    }
};