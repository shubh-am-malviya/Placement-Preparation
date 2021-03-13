long long findMinDiff(vector<long long> a, long long n, long long m){
    
    sort(a.begin(), a.end());
    
    long long left = 0, right = m-1;
    long long minDiff = INT_MAX;
    
    while (right < n) {
        
        minDiff = min(minDiff, a[right] - a[left]);
        left++;
        right++;
        
    }
    
    return minDiff;
}
