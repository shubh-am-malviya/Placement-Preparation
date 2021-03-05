int minJumps(int arr[], int n) {
    if (n <= 0) {
        return 1;
    } else if (arr[0] == 0) {
        return -1;
    }
    
    int maxReachable = arr[0], jumps = 1, stepsPossible = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (i == n-1) {
            return jumps;
        }
        
        maxReachable = max(maxReachable, arr[i] + i);
        
        stepsPossible--;
        
        if (steps == 0) {
            jumps++;
            
            if (i >= maxReachable) {
                return -1;
            }
            
            steps = maxReachable - i;
        }
    }
}
