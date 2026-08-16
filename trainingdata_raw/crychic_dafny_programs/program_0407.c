// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures (\result == 100 && i > 0) || (\result == 200 && i <= 0);
*/
int if_else_test(int i)
{
  int out;
  if ((i > 0))
  {
    out = 100;
    /*@ assert out >= 0 && out <= 2147483647; */
  }
  else
  {
    out = 200;
  }
  return out;  // Dafny implicit return
}