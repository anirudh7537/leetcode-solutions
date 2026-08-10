class Solution {
public:
vector<int> t;
    bool solve(int n ){
        if(n==0){
            return false;
        }
        if(t[n]!= -1){
            return t[n] ==1 ? true: false;
        }
        for(int i = 1; i*i<= n;i++){
            if(solve( n- (i*i))== false){
                return t[n] = true;
            }
        }
        return t[n] = false;
    }






    bool winnerSquareGame(int n) {
        t.assign(n+1,-1);
        return solve(n);
    }
};