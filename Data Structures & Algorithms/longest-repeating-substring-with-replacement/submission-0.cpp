class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest=0;
        int n=s.length();
        int l=0;
        int r=0;
        unordered_map<char,int> mpp;
        int maxFreq=0;
        for(int r=0;r<n;r++){
            mpp[s[r]]++;
            maxFreq = max(maxFreq,mpp[s[r]]);
            
            while((r-l+1)-maxFreq>k){
                mpp[s[l]]--;
                l++;
            }
            longest = max(longest,r-l+1);
        }
        return longest;
    }
};
