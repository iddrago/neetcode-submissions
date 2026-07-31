class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0;
        int r=n-1;
        int curwt=0,maxwt=0;
        while(l<r){
            curwt = (r-l)*min(heights[l],heights[r]);
            maxwt= max(maxwt,curwt);
            if(heights[l]>heights[r])r--;
            else{
                l++;
            }
        }
        return maxwt;
    }
};
