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
    int z = Multi((x - 1), y);
    r = (z + y);
  }
  return r;  // Dafny implicit return
}