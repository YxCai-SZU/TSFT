// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void dafny_main(int n)
{
  int i = 0;
  int a = 0;
  /*@ assert a >= 0 && a <= 2147483647; */
  int b = 0;
  /*@ assert b >= 0 && b <= 2147483647; */
/*@
  loop invariant 0 <= i <= n;
  loop invariant a + b == 3 * i;
  loop assigns i, a, b;
  loop variant n - i;
*/
  while ((i < n))
    {
      if (1)
      {
        a = (a + 1);
        b = (b + 2);
      }
      else
      {
        a = (a + 2);
        b = (b + 1);
      }
      i = (i + 1);
    }
}
