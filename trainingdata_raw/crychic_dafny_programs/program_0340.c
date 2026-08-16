// Generated C + ACSL

/*@
    requires x == 0;
    assigns \nothing;
    ensures \result > 3;
*/
int contract1(int x)
{
  int result;
  if (x == 3)
  {
    result = 4;
    /*@ assert result >= 0 && result <= 2147483647; */
    return result;
  }
  else
  if (x == 4)
  {
    result = 5;
    return result;
  }
  else
  {
    result = 6;
    return result;
  }
  return result;  // Dafny implicit return
}