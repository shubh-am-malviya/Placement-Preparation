bool find3Numbers(int arr[], int N, int X)
{
    sort(arr, arr+N);
    
    for (int i = 0; i < N-2; i++) {
        
        int left = i+1, right = N-1;
        int remaining = X - arr[i];
        
        while (left < right) {
            
            if (arr[left] + arr[right] == remaining) {
                return true;
            }
            else if (arr[left] + arr[right] > remaining) {
                right--;
            } else {
                left++;
            }
            
        }
    }
    
    return false;
}
