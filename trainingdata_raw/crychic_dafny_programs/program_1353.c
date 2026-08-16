// Generated C + ACSL

/*@
    requires a >= 0;
    requires b >= 0;
    assigns \nothing;
*/
void problem4(int a, int b)
{
  int i;
  int j;
  
  // Initialize i and j
  i = a;
  j = b;
  
  /*@ assert i == a && j == b; */
  /*@ assert i >= 0 && j >= 0; */
  
/*@
  loop invariant i >= 0;
  loop invariant j >= 0;
  loop invariant i + 2 * j >= 0;
  loop invariant i > 0 ==> j >= 0;
  loop invariant j > 0 ==> i >= 0;
  loop invariant i + 2 * j <= \at(i, LoopEntry) + 2 * \at(j, LoopEntry);
  loop assigns i, j;
  loop variant i + 2 * j;
*/
  while (((i > 0) && (j > 0)))
    {
      /*@ assert i > 0 && j > 0; */
      /*@ assert i + 2 * j > 0; */
      
      if ((i < j))
      {
        // Swap i and j
        int temp = i;
        i = j;
        j = temp;
        
        /*@ assert i > 0 && j > 0; */
        /*@ assert i >= j; */
      }
      else
      {
        /*@ assert i >= j; */
        /*@ assert i > 0; */
        i = (i - 1);
        /*@ assert i >= 0; */
      }
      
      /*@ assert i + 2 * j >= 0; */
    }
    
  /*@ assert !(i > 0 && j > 0); */
  /*@ assert i == 0 || j == 0; */
}