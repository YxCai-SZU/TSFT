// Generated C + ACSL

/*@
    requires step > 0;
    assigns \nothing;
*/
void BigFoot(int step)
{
  int indx = 0;
/*@
  loop invariant indx <= 42 + step;
  loop invariant step == \at(step, LoopEntry);
  loop assigns indx;
  loop variant 42 - indx + step;
*/
  while ((indx <= 42))
    {
      indx = (indx + step);
    }
  /*@ assert (indx > 42); */
}
