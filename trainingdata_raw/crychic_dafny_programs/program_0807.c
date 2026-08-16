// Generated C + ACSL

/*@
  predicate Valid(int *vals, integer len) =
    \valid(vals) && len == 4;
*/

/*@
    requires \valid_read(vals + (0 .. 3));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == vals[0] * vals[0] + vals[1] * vals[1] + vals[2] * vals[2] + vals[3] * vals[3];
*/
int AbsSquared(int *vals)
{
  int result = 0.0;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= 4;
  loop invariant result >= 0.0;
  loop invariant i == 0 ==> result == 0.0;
  loop invariant i == 1 ==> result == vals[0] * vals[0];
  loop invariant i == 2 ==> result == vals[0] * vals[0] + vals[1] * vals[1];
  loop invariant i == 3 ==> result == vals[0] * vals[0] + vals[1] * vals[1] + vals[2] * vals[2];
  loop invariant i == 4 ==> result == vals[0] * vals[0] + vals[1] * vals[1] + vals[2] * vals[2] + vals[3] * vals[3];
  loop assigns i, result;
  loop variant 4 - i;
*/
  while ((i < 4))
    {
      result = (result + (vals[i] * vals[i]));
      i = (i + 1);
    }
  return result;  // Dafny implicit return
}