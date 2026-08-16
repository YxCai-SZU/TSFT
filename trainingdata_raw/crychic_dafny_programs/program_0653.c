// Generated C + ACSL

/*@
    requires m >= 0;
    requires n >= 0;
    assigns \nothing;
    ensures \result == m * n;
*/
int Product(int m, int n)
{
  int m1 = m;
  /*@ assert m1 >= 0 && m1 <= 2147483647; */
  int res = 0;
  /*@ assert res >= 0 && res <= 2147483647; */
/*@
  loop invariant 0 <= m1 <= \at(m, LoopEntry);
  loop invariant res == \at(m, LoopEntry) * \at(n, LoopEntry) - m1 * \at(n, LoopEntry);
  loop assigns res, m1;
  loop variant m1;
*/
  while ((m1 != 0))
    {
      int n1 = n;
      /*@ assert n1 >= 0 && n1 <= 2147483647; */
/*@
  loop invariant 0 <= n1 <= \at(n, LoopEntry);
  loop invariant res == (\at(m, LoopEntry) - \at(m1, LoopEntry) + 1) * \at(n, LoopEntry) - n1;
  loop assigns res, n1;
  loop variant n1;
*/
      while ((n1 != 0))
        {
          res = (res + 1);
          n1 = (n1 - 1);
        }
      m1 = (m1 - 1);
    }
  return res;  // Dafny implicit return
}
