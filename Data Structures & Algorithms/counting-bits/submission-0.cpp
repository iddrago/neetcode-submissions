class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
           int mask=1,bits=0;
           for(int j=0;j<32;j++){
            if((mask&i)!=0) bits++;
            mask<<=1;
           }
           ans.push_back(bits);

        }
        return ans;
    }
};
