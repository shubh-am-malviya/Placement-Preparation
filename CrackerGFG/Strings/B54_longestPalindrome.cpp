string longestPalindrom(string s) {
    int n = s.length();
    int maxLength = 1;
    int start = 0;
    
    int dp[n][n];
    
    // Filling dp for substr of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    // Filling dp for substr of length 2
    for (int i = 1; i < n; i++) {
        if (s[i-1] == s[i]) {
            dp[i-1][i] = 1;
            
            if (maxLength == 1) {
                maxLength = 2;
                start = i-1;
            }
            
        } else {
            dp[i-1][i] = 0;
        }
    }
    
    // Filling dp for substr of length 3 to n
    // dp[si][ei] is palindrome if s[si] == s[ei] and dp[si+1][ei-1] == 1
    for (int i = 2; i < n; i++) {
        for (int j = i; j < n; j++) {
            int si = j-i;
            int ei = j;
            
            if (s[si] == s[ei] && dp[si+1][ei-1] == 1) {
                dp[si][ei] = 1;
                
                int  length = ei - si + 1;
                
                if (length > maxLength) {
                    maxLength = length;
                    start = si;    
                }
                
            } else {
                dp[si][ei] = 0;
            }
        }
    }
    
    return s.substr(start, maxLength);
}
