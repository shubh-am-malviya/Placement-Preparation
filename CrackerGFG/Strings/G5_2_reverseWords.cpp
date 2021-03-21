void reverseWords(string& S) {
    int start = 0, end = 0;
    
    while (end < S.length()) {
        if (S[end] != ' ') {
            end++;
        } else {
            reverse(S.begin() + start, S.begin() + end);
            start = end+1;
            end++;
        }
    }
    
    reverse(S.begin() + start, S.begin() + end); // reversing  last word
    reverse(S.begin(), S.end());
}
