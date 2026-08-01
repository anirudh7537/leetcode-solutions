class Solution {
public:
 int solve(int i, int j,vector<int>& nums ){
  if(i>j) return 0;
  if(i==j) return nums[i];
  int take_i = nums[i] + min(solve(i+2,j,nums), solve(i+1,j-1,nums));
  int take_j = nums[j] + min(solve(i+1,j-1,nums), solve(i,j-2,nums));
  return max(take_i,take_j);

 }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalScore = accumulate(begin(nums),end(nums), 0);
        int player1_score = solve(0,n-1,nums);
        int player2_score = totalScore - player1_score;
        return (player1_score>= player2_score);
    }
};