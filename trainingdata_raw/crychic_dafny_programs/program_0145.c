// Generated C + ACSL

/*@
    requires x >= -715827882;
    requires x <= 715827882;
    assigns \nothing;
    ensures \result == 3 * x;
*/
int Triple(int x)
{
  int y = (x * 2);
  /*@ assert y == 2 * x; */
  /*@ assert x >= -715827882 && x <= 715827882; */
  int r = (y + x);
  /*@ assert r == 3 * x; */
  /*@ assert r >= -2147483646 && r <= 2147483646; */
  return r;  // Dafny implicit return
}