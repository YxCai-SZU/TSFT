// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result == a || \result == b;
    ensures \result <= a && \result <= b;
*/
int Min(int a, int b)
{
  int minValue;
  if ((a <= b))
  {
    minValue = a;
    /*@ assert minValue == a; */
    /*@ assert minValue <= a && minValue <= b; */
  }
  else
  {
    minValue = b;
    /*@ assert minValue == b; */
    /*@ assert minValue <= a && minValue <= b; */
  }
  /*@ assert minValue == a || minValue == b; */
  /*@ assert minValue <= a && minValue <= b; */
  return minValue;  // Dafny implicit return
}