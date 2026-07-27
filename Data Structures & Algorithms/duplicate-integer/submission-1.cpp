class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
       unordered_map <int,int> mpp;
       for(auto it: nums){
        mpp[it]+=1;
        if(mpp[it]>1){
            return true;
        }
       }
       
       return false; 
    }
};