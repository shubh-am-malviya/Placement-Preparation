int findLongestConseqSubseq(int arr[], int N)
{
    set<int> hashSet;
    
    for (int i = 0; i < N; i++) {
      hashSet.insert(arr[i]);
    }
    
    int longestSeq = 1;
    
    for (int i = 0; i < N; i++) {
      
      if (hashSet.count(arr[i]-1) == 0) {       // if arr[i] is beginning  of sequence then find the length  of seq
          int seq = 1;
          
          int num = arr[i];
          num++;
          
          while (hashSet.count(num) > 0) {
              seq++;
              num++;
          }
          
          if (seq > longestSeq) {
              longestSeq = seq;
          }
      }
    }
    
    return longestSeq;

}
