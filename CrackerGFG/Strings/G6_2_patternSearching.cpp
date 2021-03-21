void patSearchinng(string &txt,string &pat){
    int n=txt.length();
    int m=pat.length();
    
    for(int i=0;i<=(n-m);  ) {
        int j;
        
        for(j=0;j<m;j++) {
            if(pat[j]!=txt[i+j])
            break;
        }
        
        if(j==m) {          // If pattern is found
            cout<<i<<" ";
        }
        
        if(j==0) {          // If pattern is not matched at all, we move text index by 1
            i++;
        }
        else{               // Some pattern is matched, we moved the text index ahead by j
            i=(i+j);
        }
    }
}
