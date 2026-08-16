// Generated C + ACSL

/*@
    requires n > 0;
    assigns \nothing;
    ensures \result >= 0;
*/
int MultipleReturns(int n)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= n;
  loop invariant i == \at(i, LoopEntry) + (\at(i, LoopEntry) < n ? (i - \at(i, LoopEntry)) : 0);
  loop assigns i;
  loop variant n - i;
*/
  while ((i < n))
    {
      i = (i + 1);
    }
  return i;
}
