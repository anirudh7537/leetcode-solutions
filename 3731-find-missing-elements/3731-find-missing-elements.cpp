class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty())
        return {};
        unordered_set<int> st(nums.begin(),nums.end());
        int minimum = *min_element(nums.begin(),nums.end());
        int maximum = *max_element(nums.begin(),nums.end());
        vector<int> ans;
        for(int i = minimum+1;i<maximum;i++){
           if(st.find(i)==st.end())
           ans.push_back(i);
        }
        return ans;
    }
};