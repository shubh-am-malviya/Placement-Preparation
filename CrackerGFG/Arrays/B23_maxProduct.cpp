int maxProduct(vector<int>& nums) {
    int max = INT_MIN;
    int prod = 1;
    
    // Finding max product left to right
    for (int i = 0; i < nums.size(); i++) {
        prod = prod*nums[i];
        
        if (prod > max) {
            max = prod;
        }
        
        if (prod == 0) {
            prod = 1;
        }
    }
    
    // Finding max product right to left
    prod = 1;
    
    for (int i = nums.size()-1; i >= 0; i--) {
        prod = prod*nums[i];
        
        if (prod > max) {
            max = prod;
        }
        
        if (prod == 0) {
            prod = 1;
        }
    }
    
    return max;
}
