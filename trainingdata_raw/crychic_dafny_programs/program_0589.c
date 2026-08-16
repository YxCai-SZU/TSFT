// Generated C + ACSL

/*@
    assigns \nothing;
*/
void dafny_main(void)
{
  int x = 0;
  int y = 0;
  int i = 0;
  int j = 0;
/*@
  loop invariant x - \at(x, LoopEntry) == y - \at(y, LoopEntry);
  loop invariant \at(x, LoopEntry) <= x <= 100001;
  loop invariant \at(y, LoopEntry) <= y <= 100001;
  loop invariant j - i >= 0;
  loop invariant j >= \at(j, LoopEntry);
  loop invariant i >= \at(i, LoopEntry);
  loop invariant x - y == \at(x, LoopEntry) - \at(y, LoopEntry);
  loop invariant 2 * x - 2 * y + j - i >= -1;
  loop assigns x, y, i, j;
  loop variant 100001 - x;
*/
  while ((x <= 100000))
    {
      x = (x + 1);
      y = (y + 1);
      i = (i + x);
      j = (j + y);
      if (1)
      {
        j = (j + 1);
      }
    }
  /*@ assert (j >= i); */
}
