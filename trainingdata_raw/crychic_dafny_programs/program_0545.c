// Generated C + ACSL

/*@
    assigns \nothing;
*/
void dafny_main(void)
{
  int x = 1;
  /*@ assert x >= 0 && x <= 2147483647; */
  int y = 1;
  /*@ assert y >= 0 && y <= 2147483647; */
  int t1 = 0;
  /*@ assert t1 >= 0 && t1 <= 2147483647; */
  int t2 = 0;
  /*@ assert t2 >= 0 && t2 <= 2147483647; */
/*@
  loop invariant x == y;
  loop invariant x >= \at(x, LoopEntry);
  loop invariant y >= \at(y, LoopEntry);
  loop invariant \at(x, LoopEntry) <= 100000 ==> x <= 200000;
  loop assigns x, y, t1, t2;
  loop variant 100000 - x;
*/
  while ((x <= 100000))
    {
      t1 = x;
      t2 = y;
      x = (t1 + t2);
      y = (t1 + t2);
    }
}
