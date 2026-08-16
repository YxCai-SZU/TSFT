// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result == a || \result == b || \result == c;
    ensures (\result >= a && \result <= b) || (\result >= b && \result <= a) ||
            (\result >= a && \result <= c) || (\result >= c && \result <= a) ||
            (\result >= b && \result <= c) || (\result >= c && \result <= b);
*/
int MedianOfThree(int a, int b, int c)
{
  int median;
  if ((((a <= b) && (b <= c)) || ((c <= b) && (b <= a))))
  {
    median = b;
    /*@ assert median == b; */
    /*@ assert (a <= median && median <= c) || (c <= median && median <= a); */
  }
  else
  if ((((b <= a) && (a <= c)) || ((c <= a) && (a <= b))))
  {
    median = a;
    /*@ assert median == a; */
    /*@ assert (b <= median && median <= c) || (c <= median && median <= b); */
  }
  else
  {
    median = c;
    /*@ assert median == c; */
    /*@ assert (a <= median && median <= b) || (b <= median && median <= a); */
  }
  /*@ assert median == a || median == b || median == c; */
  return median;  // Dafny implicit return
}