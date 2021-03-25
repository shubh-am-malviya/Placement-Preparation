string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else if (n == 2) {
            return "11";
        }
        
        string s = countAndSay(n-1);
        
        s = s + "$";          // Delimiter
        string res = "";
        
        int count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                count++;
            } else {
                res += to_string(count) + s[i-1];
                count = 1;
            }
        }
        
        return res;
    }
