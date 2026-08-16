// Generated C + ACSL

/*@
    requires x >= 0;
    requires y >= 0;
    requires x == y;
    assigns \nothing;
*/
void dafny_main(int x, int y)
{
  int x_out = x;
  /*@ assert x_out >= 0 && x_out <= 2147483647; */
  int y_out = y;
  /*@ assert y_out >= 0 && y_out <= 2147483647; */
  int n = 0;
  /*@ assert n >= 0 && n <= 2147483647; */
/*@
  loop invariant x_out == y_out;
  loop invariant x_out >= 0;
  loop invariant y_out >= 0;
  loop invariant n == 0;
  loop invariant x_out <= \at(x_out, LoopEntry);
  loop invariant y_out <= \at(y_out, LoopEntry);
  loop invariant \at(x_out, LoopEntry) - x_out == \at(y_out, LoopEntry) - y_out;
  loop assigns x_out, y_out;
  loop variant x_out;
*/
  while ((x_out != n))
    {
      x_out = (x_out - 1);
      y_out = (y_out - 1);
    }
}