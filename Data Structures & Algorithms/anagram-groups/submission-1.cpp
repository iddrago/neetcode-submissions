class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> ans;
      unordered_map <string,vector<string>> um;
      for(auto str : strs){
        string x = str;
        sort(x.begin(),x.end());
        um[x].push_back(str);
      }  
      for(auto it : um){
        ans.push_back(it.second);
      }
      return ans;
    }
};
