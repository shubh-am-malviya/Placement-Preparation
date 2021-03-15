int sb(int arr[], int n, int x)
{
    int minLength = INT_MAX;
    
    int left = 0, right = 0;
    int sum = arr[0];
    
    while (right < n) {
        
        if (sum > x) {
            
            if ((right-left+1) < minLength) {
                minLength = right-left+1;
            }
            
            sum -= arr[left];
            left++;
        }
        else if (right+1 < n){
            right++;
            sum += arr[right];
        } 
        else {
            break;
        }
    }
    
    return minLength;
}
