// Generated C + ACSL

/*@
    assigns \nothing;
    ensures \result == ((x % 2 == 0) ? 1 : 0);
*/
int ComputeIsEven(int x)
{
  int is_even = 0;
  /*@ assert is_even >= 0 && is_even <= 2147483647; */
  if (((x % 2) == 0))
  {
    is_even = 1;
  }
  return is_even;  // Dafny implicit return
}
