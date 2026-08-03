class Solution {
public:
int n;
int t[50001];
int solve(vector<int>& stone, int i){
    if(i>= n)
        return 0;
    if(t[i] != INT_MIN)
        return t[i];   
    int result = stone[i] - solve(stone, i+1);
    if(i+1<n)
        result = max(result,stone[i] + stone[i+1] - solve(stone,i+2));
    if(i+2<n)
        result = max(result,stone[i] + stone[i+1] + stone[i+2] - solve(stone,i+3));
    return t[i] = result;
    
}

    string stoneGameIII(vector<int>& stone) {
     n = stone.size();
    fill(t, t+ 50001, INT_MIN);
     int diff = solve(stone, 0);
    if(diff<0)
        return "Bob";
    else if (diff > 0)
        return "Alice";

        return "Tie";   
    }
};