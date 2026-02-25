class Solution:
    def maxProfit(self, prices):
        if not prices:
            return 0

        # hold: max profit when holding a stock
        # sold: max profit just after selling (cooldown applies)
        # rest: max profit when doing nothing and not holding
        hold = -prices[0]
        sold = 0
        rest = 0

        for price in prices[1:]:
            prev_hold = hold
            prev_sold = sold
            prev_rest = rest

            hold = max(prev_hold, prev_rest - price)
            sold = prev_hold + price
            rest = max(prev_rest, prev_sold)

        return max(sold, rest)