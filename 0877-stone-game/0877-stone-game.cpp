/*
=========================================================
Solution 1: Mathematical Observation (0 ms)
---------------------------------------------------------
Intuition:
- Number of piles is even.
- Total number of stones is odd.
- Alex can always choose either all even-indexed piles
  or all odd-indexed piles, whichever has more stones.
- Hence Alex always wins.

Time Complexity : O(1)
Space Complexity: O(1)
=========================================================

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

*/

/*
=========================================================
Solution 2: Memoization (Game Theory / DP)
---------------------------------------------------------
Time Complexity : O(n^2)
Space Complexity: O(n^2)

State:
solve(i,j) = Maximum stones current player can collect
             from piles[i...j].
=========================================================
*/

class Solution {
public:
    int t[501][501];

    int solve(int i, int j, vector<int>& piles) {
        if (i > j)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        int mid = solve(i + 1, j - 1, piles);

        int takeLeft =
            piles[i] + min(solve(i + 2, j, piles), mid);

        int takeRight =
            piles[j] + min(mid, solve(i, j - 2, piles));

        return t[i][j] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        memset(t, -1, sizeof(t));

        int total = accumulate(piles.begin(), piles.end(), 0);

        int alex = solve(0, piles.size() - 1, piles);
        int lee = total - alex;

        return alex >= lee;
    }
};