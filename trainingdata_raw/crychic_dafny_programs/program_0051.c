// Generated C + ACSL

/*@
    requires n >= 0;
    assigns \nothing;
*/
void dafny_main(int n)
{
  int i = 0;
  /*@ assert i >= 0 && i <= 2147483647; */
  int x = 0;
  /*@ assert x >= 0 && x <= 2147483647; */
  int y = 0;
  /*@ assert y >= 0 && y <= 2147483647; */
/*@
  loop invariant 0 <= i <= n;
  loop invariant x == \at(x, LoopEntry) + (i - \at(i, LoopEntry));
  loop invariant x == i;
  loop invariant y == i / 2;
  loop invariant 2 * y <= i <= 2 * y + 1;
  loop assigns i, x, y;
  loop variant n - i;
*/
  while ((i < n))
    {
      i = (i + 1);
      x = (x + 1);
      if (((i % 2) == 0))
      {
        y = (y + 1);
      }
      else
      {
      }
    }
}
