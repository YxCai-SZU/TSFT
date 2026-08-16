// Generated C + ACSL

/*@
    requires 0 <= x && 0 <= y;
    decreases x;
    assigns \nothing;
    ensures \result == x * y;
*/
int Multi(int x, int y)
{
  int r;
  if (x == 0)
  {
    r = 0;
    /*@ assert r >= 0 && r <= 2147483647; */
  }
  else
  {
    /*@ assert x - 1 >= 0; */
    /*@ assert x - 1 < x; */
    int z = Multi((x - 1), y);
    /*@ assert z == (x - 1) * y; */
    r = (z + y);
    /*@ assert r == (x - 1) * y + y; */
    /*@ assert r == x * y; */
  }
  return r;  // Dafny implicit return
}