// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void ex01(int n, int b)
{
  int i = 0;
  int j = 0;
  int R = 0;
/*@
  loop invariant i <= n;
  loop invariant R <= i;
  loop invariant \at(R, LoopEntry) <= R;
  loop invariant \at(i, LoopEntry) <= i;
  loop assigns i, j, R;
  loop variant n - i;
*/
  while ((i < n))
    {
      i = (i + 1);
      j = 0;
/*@
  loop invariant \at(i, LoopEntry) <= i <= n;
  loop invariant \at(R, LoopEntry) <= R <= i;
  loop invariant R - \at(R, LoopEntry) == i - \at(i, LoopEntry);
  loop invariant j == i - \at(i, LoopEntry);
  loop assigns i, j, R;
  loop variant n - i;
*/
      while (((i < n) && b))
        {
          i = (i + 1);
          j = (j + 1);
          R = (R + 1);
          /*@ assert (R <= i); */
        }
    }
  /*@ assert (i <= n); */
  /*@ assert (R <= n); */
}
