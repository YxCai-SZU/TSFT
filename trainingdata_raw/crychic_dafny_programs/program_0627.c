// Generated C + ACSL

/*@
    requires limit >= 0;
    assigns \nothing;
*/
void Skippy(int limit)
{
  int skip = 7;
  int index = 0;
/*@
  loop invariant 0 <= index <= (limit / 7 + 1) * 7;
  loop invariant index % 7 == 0;
  loop invariant index == \at(index, LoopEntry) + (((index - \at(index, LoopEntry)) / skip) * skip);
  loop assigns index;
  loop variant (limit / 7 + 1) * 7 - index;
*/
  while ((index <= limit))
    {
      index = (index + skip);
    }
  /*@ assert (index == (((limit / 7) + 1) * 7)); */
}
