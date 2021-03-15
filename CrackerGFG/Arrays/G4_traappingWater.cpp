int trappingWater(int arr[], int n){
    int left = 0, right = n-1;
    int leftMax = 0, rightMax = 0;
    int result = 0;
    
    while (left <= right) {
        
        if (arr[left] <= arr[right]) { // Means left side is lesser
            
            if (arr[left] >= leftMax) { // We cannot store water at max
                leftMax = arr[left];
            }
            else {
                result += leftMax - arr[left];    
            }
            left++;
        }
        else {  // Means Right side is lessor
            
            if (arr[right] >= rightMax) {
                rightMax = arr[right];
            }
            else {
                result += rightMax - arr[right];
            }
            right--;
        }
    }
    
    return result;
}
