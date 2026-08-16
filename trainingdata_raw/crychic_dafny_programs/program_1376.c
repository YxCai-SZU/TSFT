// Generated C + ACSL

/*@
    requires n >= 0;
    requires m >= 0;
    assigns \nothing;
*/
void CommandCompleter(int n, int m, int b)
{
  int R1 = 0;
  int R2 = 0;
  int i = 0;
  int k = 0;
/*@
  loop invariant i == k;
  loop invariant \at(i, LoopEntry) <= i <= n;
  loop invariant \at(k, LoopEntry) <= k <= n;
  loop invariant i - \at(i, LoopEntry) == k - \at(k, LoopEntry);
  loop assigns i, k;
  loop variant n - i;
*/
  while ((i < n))
    {
      i = (i + 1);
      k = (k + 1);
    }
  /*@ assert (k <= n); */
  if (b)
  {
    R1 = (R1 + k);
    /*@ assert (R1 <= n); */
  }
  else
  {
    int j = 0;
/*@
  loop invariant j >= R2;
  loop invariant j <= k;
  loop invariant \at(j, LoopEntry) <= j;
  loop invariant R2 >= \at(R2, LoopEntry);
  loop invariant R2 <= \at(R2, LoopEntry) + j - \at(j, LoopEntry);
  loop assigns j, R2;
  loop variant k - j;
*/
    while ((j < k))
      {
        if (b)
        {
          R2 = (R2 + 1);
          /*@ assert (j >= R2); */
        }
        j = (j + 1);
      }
    /*@ assert (j <= n); */
  }
  /*@ assert ((R1 + R2) <= (2 * n)); */
}
