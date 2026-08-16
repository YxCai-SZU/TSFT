// Generated C + ACSL

/*@
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
  }
  else
  {
    z = y;
    /*@ assert z == y; */
  }
  /*@ assert (x <= y ==> z == x) && (x > y ==> z == y); */
  return z;  // Dafny implicit return
}