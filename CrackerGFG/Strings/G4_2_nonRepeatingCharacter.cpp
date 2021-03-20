char nonrepeatingCharacter(string S)
{
   int count[256] = {0};

   for (char c : S) {
       count[c]++;
   }

   for (char c : S) {
       if (count[c] == 1) {
           return c;
       }
   }

   return '$';

}
