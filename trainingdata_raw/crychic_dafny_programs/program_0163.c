// Generated C + ACSL

/*@
    requires 0 < step <= 42;
    assigns \nothing;
*/
void BigFoot(int step)
{
  int indx = 0;
  /*@ assert indx == 0; */
  /*@ assert indx % step == 0; */
/*@
  loop invariant 0 <= indx <= step + 42;
  loop invariant indx % step == 0;
  loop invariant \exists integer n; n >= 0 && indx == n * step;
  loop assigns indx;
  loop variant 42 - indx + step;
*/
  while ((indx <= 42))
    {
      /*@ assert indx % step == 0; */
      indx = (indx + step);
      /*@ assert indx % step == 0; */
    }
  /*@ assert indx > 42; */
  /*@ assert indx % step == 0; */
  /*@ assert ((0 <= indx <= step + 42 && ((indx % step) == 0)) && (indx > 42)); */
}