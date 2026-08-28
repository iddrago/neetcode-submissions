class Solution {
public:
    void findPerm(int freq[], vector<int> &ds, vector<vector<int>> &ans, vector<int> nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            findPerm(freq,ds,ans,nums);
            freq[i]=0;
            ds.pop_back();
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        int freq[n];
        for(int i=0;i<n;i++) freq[i]=0;
        findPerm(freq,ds,ans,nums);
        return ans;
    }
};
