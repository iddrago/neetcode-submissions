class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> um(256, 0);
        int n =s.size();
        int m = t.size();
        int l=0,r=0,sIndex=-1,cnt=0,minlen=INT_MAX;
        for(int i=0;i<m;i++){
            um[t[i]]++;
        }
        while(r<n && l<n){
            if(um[s[r]]>0) cnt=cnt+1;
            um[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sIndex=l;
                    
                }
                um[s[l]]++;
                if(um[s[l]]>0)cnt=cnt-1;
                l++;

            }
            r=r+1;
        }
        return sIndex==-1 ? "": s.substr(sIndex,minlen);
    }
};
