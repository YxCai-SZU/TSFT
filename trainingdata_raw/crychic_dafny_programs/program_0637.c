// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result == n0 * m0;
*/
int Q3(int n0, int m0)
{
  int n;
  int m;
  int res = 0;
  /*@ assert res >= 0 && res <= 2147483647; */
  if ((n0 >= 0))
  {
    n = n0;
    m = m0;
    /*@ assert n == n0 && m == m0; */
  }
  else
  {
    n = -n0;
    m = -m0;
    /*@ assert n == -n0 && m == -m0; */
    /*@ assert n * m == n0 * m0; */
  }
  /*@ assert n >= 0; */
  /*@ assert (n0 >= 0 ==> (n == n0 && m == m0)); */
  /*@ assert (n0 < 0 ==> (n == -n0 && m == -m0 && n * m == n0 * m0)); */
  /*@ assert n * m == n0 * m0; */
  
/*@
  loop invariant 0 <= n <= \at(n, LoopEntry);
  loop invariant res + n * m == \at(n, LoopEntry) * \at(m, LoopEntry);
  loop invariant m == \at(m, LoopEntry);
  loop invariant \at(n, LoopEntry) * \at(m, LoopEntry) == n0 * m0;
  loop invariant res + n * m == n0 * m0;
  loop assigns res, n;
  loop variant n;
*/
  while ((0 < n))
    {
      res = (res + m);
      n = (n - 1);
    }
  /*@ assert n == 0; */
  /*@ assert res + n * m == n0 * m0; */
  /*@ assert res == n0 * m0; */
  return res;  // Dafny implicit return
}