// Generated C + ACSL

/*@
    requires n > 0;
    requires m > 0;
    assigns \nothing;
    ensures \result == m * n;
*/
int CalcProduct(int m, int n)
{
  int m1 = m;
  int res = 0;
  /*@ assert res >= 0 && res <= 2147483647; */
/*@
  loop invariant 0 <= m1 <= m;
  loop invariant res == (m - m1) * n;
  loop invariant \at(m, Pre) == m;
  loop invariant \at(n, Pre) == n;
  loop assigns res, m1;
  loop variant m1;
*/
  while ((m1 != 0))
    {
      int n1 = n;
      int old_res = res;
/*@
  loop invariant 0 <= n1 <= n;
  loop invariant res == old_res + (n - n1);
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
  return res;
}