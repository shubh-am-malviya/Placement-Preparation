int largestRectangleArea(vector<int>& heights) {
    
    int n = heights.size();
    vector<int> left(n), right(n);
    
    stack<int> myStack;
    
    // Filling left 
    for (int i = 0; i < n; i++) {
        int currHeight = heights[i];
        
        while (!myStack.empty() && heights[myStack.top()] >= currHeight) {
            myStack.pop();
        }
        
        if (myStack.empty()) {
            left[i] = 0;
        } else {
            left[i] = myStack.top() + 1;
        }
        
        myStack.push(i);
    }
    
    // Clearing stack for reusing
    while (!myStack.empty()) {
        myStack.pop();
    }
    
    // Filling right
    for (int i = n-1; i >= 0; i--) {
        int currHeight = heights[i];
        
        while (!myStack.empty() && heights[myStack.top()] >= currHeight) {
            myStack.pop();
        }
        
        if (myStack.empty()) {
            right[i] = n-1;
        } else {
            right[i] = myStack.top() - 1;
        }
        
        myStack.push(i);
    }
    
    // Finding maxarea
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        maxArea = max(maxArea, heights[i] * (right[i]-left[i]+1));
    }
    
    return maxArea;
}
