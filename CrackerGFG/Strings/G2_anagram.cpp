bool isAnagram(string a, string b){
    
    int count[26] = {0};
    
    for (char c : a) {
        count[c - 'a']++;
    }
    
    for (char c : b) {
        count[c - 'a']--;
    }
    
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    
    return true;
    
}
