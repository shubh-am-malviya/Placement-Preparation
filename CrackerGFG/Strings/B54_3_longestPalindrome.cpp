string longestPalindrom(string s) {
    int n = s.length();
    int start  = 0;
    int maxLength = 1;
    
    for (int i = 1; i < n; i++) {
        
        // Even size substring
        int left = i-1;
        int right = i;
        
        while (left >= 0 && right < n && s[left] == s[right]) {
            
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            
            left--;
            right++;
        }
        
        // Odd size Substring
        left = i-1;
        right = i+1;
        
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            
            left--;
            right++;
        }
    }
    
    return s.substr(start, maxLength);
}
