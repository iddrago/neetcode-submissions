class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> h(256,-1);
        int maxlen=0,l=0,r=0,len=0;
        while(r<n){
            if(h[s[r]]!=-1){
                if(h[s[r]]>=l){
                    l=h[s[r]]+1;
                }
            }
            len=r-l+1;
            maxlen=max(maxlen,len);
            h[s[r]]=r;
            r++;

        }
        return maxlen;
    }
};
