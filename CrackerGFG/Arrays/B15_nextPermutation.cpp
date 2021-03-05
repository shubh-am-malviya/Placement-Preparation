// (I) Find breakPoint from behind, arr[i] < arr[i+1]
// (II) If breakPoint is found, find justGreater number than breakPoint from behind arr[i] > arr[breakPoint]
//     (i) swap elements of breakPoint and justGreater
// (III) reverse elements after breakPoint (if breakPoint is not found, reverse all)

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int breakPoint = -1;
    
    for (int i = n-2; i >= 0; i--) {                // I
        if (nums[i] < nums[i+1]) {
            breakPoint = i;
            break;
        }
    }
    
    if (breakPoint >= 0) {                          // II
        
        int justGreater;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > nums[breakPoint]) {
                justGreater = i;
                break;
            }
        }
        
        swap(nums[breakPoint], nums[justGreater]);              // (i)
        reverse(nums.begin() + breakPoint + 1, nums.end());     // III
        
    } else {
        reverse(nums.begin(), nums.end());              // III
    }
}
