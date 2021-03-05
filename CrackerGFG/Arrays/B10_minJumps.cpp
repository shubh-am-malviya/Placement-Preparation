// Algo Down

int minJumps(int arr[], int n) {
    
    if (n <= 0) {                   // Corner Cases
        return 1;
    } else if (arr[0] == 0) {
        return -1;
    }
    
    
    int jumps[n];                   // (I)
    jumps[n-1] = 0;
    
    
    for (int i = n-2; i>=0; i--) {              // (II)
        if (arr[i] == 0) {
            jumps[i] = INT_MAX;
        }
        else if (arr[i] + i >= n-1) {
            jumps[i] = 1;
        } else {
            jumps[i] = 1 + getMinJumps(i, arr[i], jumps, n);
        }
    }
    
    
    if (jumps[0] < 0 || jumps[0] >= INT_MAX) {              // (III)
        return -1;
    }
    return jumps[0];
    
}

// (I)
// jumps is the dp array
// jumps will store the no of jump required from i to reach end
// for last element 0 jump is required to reach end

// (II)
// Calculating jumps required for each index to reach end
// if index element is zero, we can't go anywhere. hence INT_MAX
// if index element can reach last element, then jump[i] = 1
// if index can't reach last element, we check minimum jump required by elements of  its reach and add 1

// (III)
// Returning jumps required from first element to reach last
