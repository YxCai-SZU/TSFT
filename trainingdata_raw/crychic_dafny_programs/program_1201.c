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
  loop invariant m1 >= 0;
  loop invariant m1 <= m;
  loop invariant res == (m - m1) * n;
  loop invariant n == \at(n, Pre);
  loop invariant m == \at(m, Pre);
  loop assigns res, m1;
  loop variant m1;
*/
  while ((m1 != 0))
    {
      int n1 = n;
      int old_res = res;
/*@
  loop invariant n1 >= 0;
  loop invariant res == old_res + (n - n1);
  loop invariant n == \at(n, Pre);
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