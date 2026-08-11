class Solution {
public:
    int cnt (int n){
        int len = 0;
        while(n!=0){
            n = n/10;
            len ++;
        }
        return len;
            }
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i <nums.size(); i++){
            if(cnt(nums[i])%2 == 0){
                count++;
            }
        }
        return count;
        
    }
};