class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int n = s.size();
        int r=n-1;
        int winlen=0;
        int ans=0;
        vector<int> freq(128,0);
        for(int i=l;i<=r;i++){
            freq[s[i]]++;
            winlen++;
            while(freq[s[i]]>1){
                freq[s[l]]--;
                l++;
                winlen--;
            }
            ans=max(ans,winlen);
        }
        return ans;
    }
};
