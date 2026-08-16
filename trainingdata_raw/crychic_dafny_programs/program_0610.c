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
  }
  else
  {
    n = -n0;
    m = -m0;
  }
/*@
  loop invariant 0 <= n;
  loop invariant n0 >= 0 ==> (n0 - n) * m == res && n <= n0;
  loop invariant n0 < 0 ==> (-n0 - n) * m == res && n <= -n0;
  loop assigns n, res;
  loop variant n;
*/
  while ((0 < n))
    {
      res = (res + m);
      n = (n - 1);
    }
  return res;
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