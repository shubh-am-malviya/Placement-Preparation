char nonrepeatingCharacter(string S)
{
   int firstOccurence[256];
   memset(firstOccurence, -1, sizeof(firstOccurence));

   for (int i = 0; i < S.length(); i++) {
       char c = S[i];

       if (firstOccurence[c] == -1) {
           firstOccurence[c] = i;    // First occurence
       } 
       else {
           firstOccurence[c] = -2;   // Repeating character
       }
   }

   int  index = INT_MAX;

   for (int i = 0; i < 256; i++) {
       if ((firstOccurence[i] != -1) && (firstOccurence[i] != -2)) {
           index = min(index, firstOccurence[i]);
       }
   }

   return (index == INT_MAX) ? '$' : S[index];
}
