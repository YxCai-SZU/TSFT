// Generated C + ACSL

/*@
    assigns \nothing;
*/
void CalDiv(void)
{
  int x = 0;
  int y = 191;
/*@
  loop invariant 0 <= y <= 191;
  loop invariant 7 * x + y == 191;
  loop invariant x >= 0;
  loop invariant y == 191 - 7 * x;
  loop assigns x, y;
  loop variant y;
*/
  while ((7 <= y))
    {
      x = (x + 1);
      /*@ assert x >= 0 && x <= 2147483647; */
      y = (191 - (7 * x));
      /*@ assert y >= 0 && y <= 2147483647; */
    }
}