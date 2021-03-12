int findLongestConseqSubseq(int arr[], int N)
{
  sort(arr, arr+N);
  
  int longestSeq = 1;
  int i = 0;
  
  while (i < N) {
      int  currseq = 1;
      i++;
      
      while (i < N && (arr[i] == arr[i-1]+1 || arr[i] == arr[i-1])) {
          
          if (arr[i] != arr[i-1]) {
              currseq++;
          }
          
          i++;
      }
      
      if (currseq > longestSeq) {
          longestSeq = currseq;
      }
  }
  
  return longestSeq;
  
}
