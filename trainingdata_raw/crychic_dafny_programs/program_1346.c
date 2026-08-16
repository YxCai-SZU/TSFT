// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures x <= y ==> \result == x;
    ensures x > y ==> \result == y;
*/
int Min(int x, int y)
{
  int z;
  if ((x <= y))
  {
    z = x;
    /*@ assert z == x; */
    /*@ assert x <= y; */
  }
  else
  {
    z = y;
    /*@ assert z == y; */
    /*@ assert x > y; */
  }
  return z;  // Dafny implicit return
}