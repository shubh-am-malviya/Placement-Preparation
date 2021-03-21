void patternSearch(string &txt, string &pat) {
    int  n = txt.length();
    int m = pat.length();
    
    for (int i = 0; i <= n-m; i++) {
        int j;
        
        for (j = 0; j < m; j++) {
            if (pat[0] != txt[i+j])
                break;
        }
        
        if (j == m) {
            cout << i << " ";
        }
    }
}
