// Generated C + ACSL

/*@
    requires m >= 0;
    requires n >= 0;
    assigns \nothing;
    ensures \result == m * n;
*/
int Product1(int m, int n)
{
  int m1 = 0;
  /*@ assert m1 >= 0 && m1 <= 2147483647; */
  int n1 = 0;
  /*@ assert n1 >= 0 && n1 <= 2147483647; */
  int res = 0;
  /*@ assert res >= 0 && res <= 2147483647; */
/*@
  loop invariant 0 <= m1 <= m;
  loop invariant res == m1 * n;
  loop assigns m1, n1, res;
  loop variant m - m1;
*/
  while ((m1 < m))
    {
      n1 = 0;
/*@
  loop invariant 0 <= n1 <= n;
  loop invariant res == \at(res, LoopEntry) + n1;
  loop invariant res == \at(m1, LoopEntry) * n + n1;
  loop assigns n1, res;
  loop variant n - n1;
*/
      while ((n1 < n))
        {
          res = (res + 1);
          n1 = (n1 + 1);
        }
      m1 = (m1 + 1);
    }
  return res;  // Dafny implicit return
}
