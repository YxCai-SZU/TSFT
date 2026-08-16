// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result == a || \result == b;
    ensures \result >= a && \result >= b;
*/
int Max(int a, int b)
{
  int maxValue;
  if ((a >= b))
  {
    maxValue = a;
    /*@ assert maxValue == a; */
    /*@ assert maxValue >= b; */
  }
  else
  {
    maxValue = b;
    /*@ assert maxValue == b; */
    /*@ assert maxValue >= a; */
  }
  /*@ assert maxValue == a || maxValue == b; */
  /*@ assert maxValue >= a && maxValue >= b; */
  return maxValue;  // Dafny implicit return
}