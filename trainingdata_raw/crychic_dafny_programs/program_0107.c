// Generated C + ACSL

/*@
    requires n > 0;
    assigns \nothing;
*/
void dafny_main(int n)
{
  int x = 0;
  /*@ assert x >= 0 && x <= 2147483647; */
  int m = 0;
  /*@ assert m >= 0 && m <= 2147483647; */
/*@
  loop invariant 0 <= x <= n;
  loop invariant 0 <= m < n;
  loop assigns x, m;
  loop variant n - x;
*/
  while ((x < n))
    {
      if (1)
      {
        m = x;
      }
      else
      {
      }
      x = (x + 1);
    }
}
