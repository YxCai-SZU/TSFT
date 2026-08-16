// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result <= a && \result <= b && \result <= c;
    ensures \result == a || \result == b || \result == c;
*/
int MinOfThree(int a, int b, int c)
{
  int min;
  if (((a <= b) && (a <= c)))
  {
    min = a;
    /*@ assert min == a; */
    /*@ assert min <= b && min <= c; */
  }
  else
  if (((b <= a) && (b <= c)))
  {
    min = b;
    /*@ assert min == b; */
    /*@ assert min <= a && min <= c; */
  }
  else
  {
    min = c;
    /*@ assert min == c; */
    /*@ assert min <= a && min <= b; */
  }
  /*@ assert min == a || min == b || min == c; */
  /*@ assert min <= a && min <= b && min <= c; */
  return min;  // Dafny implicit return
}