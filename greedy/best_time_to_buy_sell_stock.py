from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        min_price = float('inf')
        max_profit = 0

        for price in prices:

            # Update minimum buying price
            if price < min_price:
                min_price = price

            # Calculate current profit
            profit = price - min_price

            # Update maximum profit
            if profit > max_profit:
                max_profit = profit

        return max_profit


# Testing locally
prices = [7, 1, 5, 3, 6, 4]

result = Solution().maxProfit(prices)

print(result)