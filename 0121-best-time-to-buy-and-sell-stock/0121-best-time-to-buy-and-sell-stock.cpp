#include<cmath>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        float min_price = INFINITY;
        float max_profit = 0;
        int n = prices.size();
        for(int price : prices){
            if(price<min_price){
                min_price = price;
            }
            float profit = price - min_price;
            if(profit> max_profit){
                max_profit = profit;
            }

        }   
        return max_profit;
        
         }
};