// Generated C + ACSL

/*@
    requires n <= 101;
    assigns \nothing;
    ensures \result == 91;
*/
int mc91(int n)
{
  int m;
  int c;
  c = 1;
  m = n;
/*@
  loop invariant m <= 111;
  loop invariant m > 100 && c == 1 ==> m == 101;
  loop invariant c == 0 ==> m == 91;
  loop invariant c >= 0;
  loop invariant m > 100 ==> c >= 1;
  loop invariant \at(c, LoopEntry) == 0 ==> c == 0 && m == 91;
  loop assigns m, c;
  loop variant 21 * c + (400 - 2 * m);
*/
  while ((c > 0))
    {
      if ((m > 100))
      {
        m = (m - 10);
        c = (c - 1);
      }
      else
      {
        m = (m + 11);
        c = (c + 1);
      }
    }
  return m;
}
