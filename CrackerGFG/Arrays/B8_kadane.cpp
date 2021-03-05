// Using Kadane algo

int maxSubarraySum(int arr[], int n){
        
    int maxEndingHere = 0, maxSoFar = 0;

    for (int i = 0; i < n; i++) {
        maxEndingHere += arr[i];

        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }

        if (maxSoFar < maxEndingHere) {
            maxSoFar = maxEndingHere;
        }
    }

    return maxSoFar;

}
