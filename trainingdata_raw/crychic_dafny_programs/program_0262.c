// Generated C + ACSL

/*@
    requires -46340 <= n0 <= 46340;
    requires -46340 <= m0 <= 46340;
    assigns \nothing;
    ensures \result == n0 * m0;
*/
int mult(int n0, int m0)
{
  int n;
  int m;
  int res = 0;
  /*@ assert res >= 0 && res <= 2147483647; */
  if ((n0 >= 0))
  {
    n = n0;
    m = m0;
  }
  else
  {
    n = -n0;
    m = -m0;
  }
  
  /*@ assert n >= 0; */
  /*@ assert n0 >= 0 ==> (n == n0 && m == m0); */
  /*@ assert n0 < 0 ==> (n == -n0 && m == -m0); */
  /*@ assert m * n == n0 * m0; */
  
/*@
  loop invariant 0 <= n <= \at(n, LoopEntry);
  loop invariant m * n + res == \at(m, LoopEntry) * \at(n, LoopEntry);
  loop invariant m == \at(m, LoopEntry);
  loop invariant \at(m, LoopEntry) * \at(n, LoopEntry) == n0 * m0;
  loop assigns res, n;
  loop variant n;
*/
  while ((0 < n))
    {
      res = (res + m);
      n = (n - 1);
    }
  
  /*@ assert n == 0; */
  /*@ assert m * n + res == n0 * m0; */
  /*@ assert res == n0 * m0; */
  
  return res;  // Dafny implicit return
}