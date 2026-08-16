// Generated C + ACSL

/*@
  predicate Valid(real s) =
    0.0 <= s && s <= 1.0;
*/

/*@
    assigns \nothing;
    ensures \result == 0 || \result == 1;
*/
int Pull(void)
{
  int r; /* unsupported init: Microsoft.Dafny.HavocRhs */
  int reward;
  if (r)
  {
    reward = 1;
    /*@ assert reward >= 0 && reward <= 2147483647; */
  }
  else
  {
    reward = 0;
  }
  return reward;  // Dafny implicit return
}