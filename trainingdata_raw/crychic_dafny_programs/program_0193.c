// Generated C + ACSL

/*@
    requires x > 0;
    assigns \nothing;
*/
void dafny_main(int x)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int j = 0;
  /*@ assert j >= 0 && j <= 2147483647; */
/*@
  loop invariant 0 <= i <= x;
  loop invariant j == 2 * i;
  loop invariant j - \at(j, LoopEntry) == 2 * (i - \at(i, LoopEntry));
  loop assigns i, j;
  loop variant x - i;
*/
  while ((i < x))
    {
      j = (j + 2);
      i = (i + 1);
    }
}
