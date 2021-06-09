int maxProfit(vector<int>& prices) {
        
        /*
            We can peform as many buys and sells as we want
            The only catch is, before buying, we have to sell the previous stock and then buy the next one
            
            So, basically we are planning to sell whenever current is greater than previous
            and profit would be, whatever we get by (selling today's stock - purchasing yesterday's stock)
        
        */
        
        
        
        int profit = 0;
        for(int i = 1; i<prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
            {
                profit += (prices[i]-prices[i-1]);
            }
        }
        
        return profit;
    }