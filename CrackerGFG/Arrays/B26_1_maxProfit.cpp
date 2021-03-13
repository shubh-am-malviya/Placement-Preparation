int getProfit(vector<int> &prices, int start, int end) {
    int profit = 0;
    int min = prices[start];
    
    for (int i = start+1; i <= end; i++) {
        if (prices[i] < min) {
            min = prices[i];
        }
        
        int currProfit = prices[i] - min;
        
        if (currProfit > profit) {
            profit = currProfit;
        }
    }
    
    return profit;
}
 
int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    
    for (int i = 1; i < prices.size(); i++) {
        int profit1 = getProfit(prices, 0, i);
        int profit2 = getProfit(prices, i+1, prices.size()-1);
        
        maxProfit = max(maxProfit, profit1 + profit2);
    }
    
    return maxProfit;
}
