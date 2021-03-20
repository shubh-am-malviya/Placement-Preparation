bool isSubSequence(string A, string B) 
{
    if (A.length() == 0) {
        return true;
    }
    
    for (int i = 0; i < B.length(); i++) {
        if (A[0] == B[i]) {
            return isSubSequence(A.substr(1), B.substr(i+1));
        }
    }
    
    return false;
}
