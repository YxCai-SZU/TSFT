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
  /*@ assert res == 0; */
  
/*@
  loop invariant n >= 0;
  loop invariant n0 >= 0 ==> m == m0;
  loop invariant n0 < 0 ==> m == -m0;
  loop invariant n0 >= 0 ==> res == (n0 - n) * m0;
  loop invariant n0 < 0 ==> res == (-n0 - n) * (-m0);
  loop invariant n0 >= 0 ==> res + n * m == n0 * m0;
  loop invariant n0 < 0 ==> res + n * m == n0 * m0;
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
  /*@ assert n0 < 0 ==> res == n0 * m0; */
  
  return res;
}