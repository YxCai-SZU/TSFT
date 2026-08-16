// Generated C + ACSL

/*@
    requires n1 >= 0 && n1 <= 2147483647;
    requires n2 >= 0 && n2 <= 2147483647;
    assigns \nothing;
    ensures (n1 > n2) ==> (\result == n1);
    ensures (n2 > n1) ==> (\result == n2);
    ensures (n1 == n2) ==> (\result == n1);
    ensures \result >= 0 && \result <= 2147483647;
    ensures \result >= n1 && \result >= n2;
    ensures \result == n1 || \result == n2;
*/
int Max(int n1, int n2)
{
  int max = n1;
  /*@ assert max == n1; */
  /*@ assert max >= 0; */
  /*@ assert max <= 2147483647; */
  if ((n2 > max))
  {
    max = n2;
    /*@ assert max == n2; */
    /*@ assert max > n1; */
  }
  /*@ assert max >= n1 && max >= n2; */
  /*@ assert max == n1 || max == n2; */
  return max;  // Dafny implicit return
}