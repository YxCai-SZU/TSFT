// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures (a == b) ==> (\result == 1);
    ensures (a != b) ==> (\result == 0);
*/
int Compare(int a, int b)
{
  int eq;
  if (a == b)
  {
    eq = 1;
    /*@ assert eq >= 0 && eq <= 2147483647; */
  }
  else
  {
    eq = 0;
  }
  return eq;  // Dafny implicit return
}