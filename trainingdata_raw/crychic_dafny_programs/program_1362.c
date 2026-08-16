// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void m(int n)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= n + 2;
  loop invariant i >= \at(i, LoopEntry);
  loop assigns i;
  loop variant n - i;
*/
  while ((i < n))
    {
      i = (i + 1);
    }
  /*@ assert (i <= (n + 2)); */
}
