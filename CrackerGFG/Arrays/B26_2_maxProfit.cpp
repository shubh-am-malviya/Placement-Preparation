int maxProfit(vector<int>& prices) {
    int n = prices.size();
    
    int* profit = new int[n];
    for (int i = 0; i < n; i++) {
        profit[i] = 0;
    }
    
    // Maximum profit in one transaction
    int ma = prices[n-1];
    
    profit[n-1] = 0;
    
    for (int i = n-2; i >= 0; i--) {
        if (prices[i] > ma) {
            ma = prices[i];
        }
        
        profit[i] = max(ma-prices[i], profit[i+1]);
    }
    
    // Maximum profit in two transaction
    int mi = prices[0];
    
    for (int i = 1; i < n; i++) {
        if (prices[i] < mi) {
            mi = prices[i];
        }
        
        profit[i] = max(profit[i-1], prices[i]-mi + profit[i]);
    }
    
    return profit[n-1];
}
