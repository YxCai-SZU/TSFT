// Generated C + ACSL

/*@
    requires m >= 0;
    requires n >= 0;
    assigns \nothing;
    ensures \result == m * n;
*/
int CalcProduct(int m, int n)
{
  int m1 = m;
  /*@ assert m1 >= 0 && m1 <= 2147483647; */
  int res = 0;
  /*@ assert res >= 0 && res <= 2147483647; */
/*@
  loop invariant 0 <= m1 <= m;
  loop invariant res == (m - m1) * n;
  loop assigns res, m1;
  loop variant m1;
*/
  while ((m1 != 0))
    {
      int n1 = n;
      /*@ assert n1 >= 0 && n1 <= 2147483647; */
      int old_res = res;
/*@
  loop invariant 0 <= n1 <= n;
  loop invariant res == \at(res, LoopEntry) + (n - n1);
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
