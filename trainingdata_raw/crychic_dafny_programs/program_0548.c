// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures n1 > n2 ==> \result == n1;
    ensures n2 > n1 ==> \result == n2;
    ensures n1 == n2 ==> \result == n1;
*/
int Max(int n1, int n2)
{
  int max = n1;
  /*@ assert max == n1; */
  /*@ assert max >= n1; */
  if ((n2 > max))
  {
    max = n2;
    /*@ assert max == n2; */
    /*@ assert max > n1; */
  }
  /*@ assert max >= n1 && max >= n2; */
  /*@ assert (max == n1 && n1 >= n2) || (max == n2 && n2 > n1); */
  return max;  // Dafny implicit return
}