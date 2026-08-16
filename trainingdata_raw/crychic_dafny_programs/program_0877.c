// Generated C + ACSL

/*@
    assigns \nothing;
*/
void BreakExample(void)
{
  int count = 0;
/*@
  loop invariant 0 <= count <= 3;
  loop invariant count == \at(count, LoopEntry) + \at(count, LoopCurrent) - \at(count, LoopEntry);
  loop invariant \at(count, LoopEntry) <= count;
  loop assigns count;
  loop variant 3 - count;
*/
  while ((count < 3))
    {
      count = (count + 1);
      if ((count == 2))
      {
        break;;
      }
      /* unsupported stmt: print count, "\n"; */
    }
}
