vector<int> factorial(int N){
    vector<int> ans;
    
    if (N == 1) {
        ans.push_back(1);
        return ans;
    }
    
    vector<int> smallAns = factorial(N-1);
    int carry = 0;
    
    for (int i = smallAns.size()-1; i >= 0; i--) {
        int temp = N*smallAns[i] + carry;
        
        ans.push_back(temp%10);
        carry = temp / 10;
    }
    
    while (carry > 0) {
        ans.push_back(carry % 10);
        carry =  carry/10;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
