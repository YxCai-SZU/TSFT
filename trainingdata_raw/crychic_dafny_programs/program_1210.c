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
  /*@ assert res == 0; */
  if ((n0 >= 0))
  {
    n = n0;
    m = m0;
    /*@ assert n == n0 && m == m0; */
    /*@ assert n >= 0; */
  }
  else
  {
    n = -n0;
    m = -m0;
    /*@ assert n == -n0 && m == -m0; */
    /*@ assert n >= 0; */
  }
  /*@ assert n >= 0; */
  /*@ assert n0 >= 0 ==> (n == n0 && m == m0); */
  /*@ assert n0 < 0 ==> (n == -n0 && m == -m0); */
  /*@ assert res == 0; */
/*@
  loop invariant 0 <= n <= \at(n, LoopEntry);
  loop invariant \at(n, LoopEntry) == (n0 >= 0 ? n0 : -n0);
  loop invariant m == (n0 >= 0 ? m0 : -m0);
  loop invariant res == (\at(n, LoopEntry) - n) * m;
  loop invariant n0 >= 0 ==> res == (n0 - n) * m0;
  loop invariant n0 < 0 ==> res == (-n0 - n) * (-m0);
  loop invariant res >= 0 || res < 0;
  loop assigns res, n;
  loop variant n;
*/
  while ((0 < n))
    {
      res = (res + m);
      n = (n - 1);
    }
  /*@ assert n == 0; */
  /*@ assert n0 >= 0 ==> res == n0 * m0; */
  /*@ assert n0 < 0 ==> res == (-n0) * (-m0); */
  /*@ assert n0 < 0 ==> res == n0 * m0; */
  return res;  // Dafny implicit return
}

/*@
    assigns \nothing;
*/
void Main(void)
{
  int r = Q3(2, 5);
  /*@ assert (r == 10); */
  int i = 0;
/*@
  loop invariant 0 <= i <= 100;
  loop invariant \at(i, LoopEntry) <= i;
  loop assigns i, r;
  loop variant 100 - i;
*/
  while ((i < 100))
    {
      r = Q3(i, i);
      /*@ assert (r == (i * i)); */
      i = (i + 1);
    }
}