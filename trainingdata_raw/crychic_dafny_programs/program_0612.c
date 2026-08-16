// Generated C + ACSL

/*@
    assigns \nothing;
*/
void Main(void)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= 2;
  loop invariant i == \at(i, LoopEntry) + (\at(i, LoopEntry) < 2 ? (i - \at(i, LoopEntry)) : 0);
  loop assigns i;
  loop variant 2 - i;
*/
  while ((i < 2))
    {
      i = (i + 1);
    }
  /*@ assert (1 < 2); */
  /*@ assert (2 < 3); */
  /*@ assert (3 < 4); */
}
