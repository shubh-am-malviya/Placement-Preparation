bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    int count[256] = {0};

    for (int i = 0; i < s1.length(); i++) {
        count[s1[i]]++;
    }

    for (int i = 0; i < s2.length(); i++) {
        count[s2[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

int search(string pat, string txt) {
    int n = txt.length();
    int m = pat.length();
    int count = 0;

    for (int i = 0; i <= n-m; i++) {
        string window = txt.substr(i, m);

        if (isAnagram(window, pat)) {
            count++;
        }
    }

    return count;
}
