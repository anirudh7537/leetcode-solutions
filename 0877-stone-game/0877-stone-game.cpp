class Solution {
public:
int t[501][501];
     
        int solve(int i, int j, vector<int>& piles){
            if(i>j)
            return 0;
            if(t[i][j] != -1)
            return t[i][j];
            int take_i = piles[i] + min(solve(i+2,j,piles),solve(i+1,j-1,piles));
            int take_j = piles[j] + min(solve(i+1,j-1, piles),solve(i,j-2, piles));
            return t[i][j] = max(take_i,take_j);
        }
        bool stoneGame(vector<int>& piles){
        memset(t, -1, sizeof(t));
        int total = accumulate(begin(piles),end(piles),0);
        int player_1 = solve(0, piles.size()-1, piles);
        int player_2 = total - player_1;
        return player_1 >= player_2;
    }
};