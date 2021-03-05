// O(n) time & O(n) space | array not modified

int findDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    
    int  dup;
    
    for (int i : nums) {
        if (s.count(i) > 0) {
            dup = i;
            break;
        }
        s.insert(i);
    }
    
    return dup;
}





// O(n log n) time & O(1) space | array modified

int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size()-1; i++) {
        if (nums[i] == nums[i+1]) {
            return nums[i];
        }
    }
    
    return -1;
}





// O(n) time & O(1) space | array not modified
// Cycle detection method (Tortoise method)

int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0, finder = 0;
    
    while (1)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        if (slow == fast)
            break;
    }
    
    
    while (1)
    {
        finder = nums[finder];
        slow = nums[slow];
        
        if (finder == slow)
            return finder;
    }
}
