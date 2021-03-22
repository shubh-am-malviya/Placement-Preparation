bool isFreqSame(int* freqPat, int* freqTxt) {
    for (int i = 0; i < 256; i++) {
        if (freqPat[i] != freqTxt[i]) {
            return false;
        }
    }
    
    return true;
}

int search(string pat, string txt) {
    int freqPat[256] = {0};
    int freqTxt[256] = {0};
    
    int n = txt.length(), m = pat.length();
    
    // filling of pattern and first window freq of text
    for (int i = 0; i < m; i++) {
        freqPat[pat[i]]++;
        freqTxt[txt[i]]++;
    }
    
    int count = 0;
    // Compare window freq with pat freq and then update count
    // Move the window ahead
    for (int i = m; i < n; i++) {
        if (isFreqSame(freqPat, freqTxt)) {
            count++;
        }
        
        // Moving window ahead by updating  freq
        
        freqTxt[txt[i-m]]--;    // Subtracting freq of left char of window
        freqTxt[txt[i]]++;      // Increasing freq of next char in the window
    }
    
    if (isFreqSame(freqPat, freqTxt)) {
        count++;
    }
    
    return count;
}
