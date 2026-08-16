// Generated C + ACSL

/*@
    assigns \nothing;
    ensures (a >= 0 ==> \result <= a) && (a < 0 ==> \result <= -1 * a);
    ensures (b >= 0 ==> \result <= b) && (b < 0 ==> \result <= -1 * b);
    ensures (c >= 0 ==> \result <= c) && (c < 0 ==> \result <= -1 * c);
    ensures \result >= 0;
*/
int Min(int a, int b, int c)
{
  int a_abs = a;
  int b_abs = b;
  int c_abs = c;
  int m;
  if ((a_abs < 0))
  {
    a_abs = (a_abs * -1);
  }
  if ((b_abs < 0))
  {
    b_abs = (b_abs * -1);
  }
  if ((c_abs < 0))
  {
    c_abs = (c_abs * -1);
  }
  if (((a_abs <= b_abs) && (a_abs <= c_abs)))
  {
    m = a_abs;
    /*@ assert m >= 0 && m <= 2147483647; */
  }
  else
  if (((b_abs <= a_abs) && (b_abs <= c_abs)))
  {
    m = b_abs;
  }
  else
  if (((c_abs <= a_abs) && (c_abs <= b_abs)))
  {
    m = c_abs;
  }
  return m;  // Dafny implicit return
}