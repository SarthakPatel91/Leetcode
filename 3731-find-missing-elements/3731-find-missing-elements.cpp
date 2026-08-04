class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }
        vector<int>ans;

        for(int i=mn+1;i<mx;i++){
            if(mp.find(i)==mp.end())
            ans.push_back(i);
        }

        return ans;
    }
};