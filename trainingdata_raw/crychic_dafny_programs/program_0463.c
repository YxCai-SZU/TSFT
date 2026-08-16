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
  i = a;
  j = b;
  
/*@
  loop invariant i >= 0;
  loop invariant j >= 0;
  loop invariant i + 2 * j >= 0;
  loop invariant (i == 0 || j == 0) ==> !(i > 0 && j > 0);
  loop invariant i + j <= a + b;
  loop invariant 0 <= i + 2*j <= a + 2*b;
  loop assigns i, j;
  loop variant i + 2 * j;
*/
  while (((i > 0) && (j > 0)))
    {
      /*@ assert i > 0 && j > 0; */
      /*@ assert i + 2*j > 0; */
      
      if ((i < j))
      {
        int tmp = i;
        i = j;
        j = tmp;
        /*@ assert i >= j; */
        /*@ assert i > 0; */
      }
      else
      {
        /*@ assert i >= j; */
        /*@ assert i > 0; */
        i = (i - 1);
        /*@ assert i >= 0; */
      }
      
      /*@ assert i + 2*j >= 0; */
    }
    
  /*@ assert !(i > 0 && j > 0); */
}