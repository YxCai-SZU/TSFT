// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result == m0 * n0;
*/
int Q3(int n0, int m0)
{
  int n;
  int m;
  int res = 0;
  /*@ assert res >= 0 && res <= 2147483647; */
  if ((n0 >= 0))
  {
    /* unsupported stmt: n, m := n0, m0; */
    n = n0;
    m = m0;
    /*@ assert n == n0 && m == m0; */
    /*@ assert n * m == n0 * m0; */
  }
  else
  {
    /* unsupported stmt: n, m := -n0, -m0; */
    n = -n0;
    m = -m0;
    /*@ assert n == -n0 && m == -m0; */
    /*@ assert n * m == n0 * m0; */
  }
  /*@ assert n >= 0; */
  /*@ assert n * m == n0 * m0; */
  /*@ assert res == 0; */
  /*@ assert res + m * n == n0 * m0; */
/*@
  loop invariant 0 <= n <= \at(n, LoopEntry);
  loop invariant res == \at(res, LoopEntry) + \at(m, LoopEntry) * (\at(n, LoopEntry) - n);
  loop invariant \at(m, LoopEntry) * \at(n, LoopEntry) == res + \at(m, LoopEntry) * n;
  loop invariant m == \at(m, LoopEntry);
  loop invariant res + m * n == \at(res, LoopEntry) + \at(m, LoopEntry) * \at(n, LoopEntry);
  loop invariant \at(m, LoopEntry) * \at(n, LoopEntry) == m0 * n0;
  loop invariant res + m * n == m0 * n0;
  loop assigns res, n;
  loop variant n;
*/
  while ((0 < n))
    {
      /*@ assert n > 0; */
      /*@ assert res + m * n == m0 * n0; */
      res = (res + m);
      /*@ assert res == \at(res, LoopCurrent) + m; */
      n = (n - 1);
      /*@ assert n == \at(n, LoopCurrent) - 1; */
      /*@ assert res + m * n == m0 * n0; */
    }
  /*@ assert n == 0; */
  /*@ assert res + m * n == m0 * n0; */
  /*@ assert res == m0 * n0; */
  return res;  // Dafny implicit return
}