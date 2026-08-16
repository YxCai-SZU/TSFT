// Generated C + ACSL

/*@
    assigns \nothing;
    ensures (n1 > n2) ==> (\result == n1);
    ensures (n2 > n1) ==> (\result == n2);
    ensures (n1 == n2) ==> (\result == n1);
    ensures \result == n1 || \result == n2;
    ensures \result >= n1 && \result >= n2;
*/
int Max(int n1, int n2)
{
  int max = n1;
  /*@ assert max == n1; */
  if ((n2 > max))
  {
    max = n2;
    /*@ assert max == n2; */
    /*@ assert max > n1; */
  }
  /*@ assert (n2 > n1 ==> max == n2) && (n2 <= n1 ==> max == n1); */
  /*@ assert max >= n1 && max >= n2; */
  return max;  // Dafny implicit return
}

/*@
    requires \true;
    assigns \nothing;
    ensures (a > b ==> \result == a) && (a <= b ==> \result == b);
    ensures \result >= a && \result >= b;
*/
int Testing(int a, int b)
{
  int result = Max(a, b);
  /*@ assert result == a || result == b; */
  /*@ assert result >= a && result >= b; */
  if ((a > b))
  {
    /*@ assert (result == a); */
  }
  else
  if ((a <= b))
  {
    /*@ assert (result == b); */
  }
  return result;  // Dafny implicit return
}