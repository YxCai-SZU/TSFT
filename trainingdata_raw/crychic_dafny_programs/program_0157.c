// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result == 3 * x;
*/
int Triple(int x)
{
  int r;
  if ((x == 0))
  {
    r = 0;
    /*@ assert r >= 0 && r <= 2147483647; */
  }
  else
  {
    int y = (2 * x);
    r = (x + y);
  }
  return r;  // Dafny implicit return
}