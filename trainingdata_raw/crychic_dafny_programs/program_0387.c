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
  loop invariant indx >= 0;
  loop invariant indx % step == 0;
  loop invariant indx >= \at(indx, LoopEntry);
  loop assigns indx;
  loop variant 42 - indx;
*/
  while ((indx <= 42))
    {
      indx = (indx + step);
    }
  /*@ assert (indx > 42); */
  /*@ assert indx <= 42 + step; */
  /*@ assert indx % step == 0; */
}