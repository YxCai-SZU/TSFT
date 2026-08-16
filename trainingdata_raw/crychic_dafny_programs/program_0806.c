// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= a && \result >= b;
    ensures \result == a || \result == b;
*/
int FindMax(int a, int b)
{
  if ((a > b))
  {
    return a;
  }
  return b;
}

/*@
    requires \true;
    assigns \nothing;
    ensures \result >= a && \result >= b && \result >= c;
    ensures \result == a || \result == b || \result == c;
*/
int FindMaxThree(int a, int b, int c)
{
  int temp = FindMax(b, c);
  /*@ assert temp >= b && temp >= c; */
  /*@ assert temp == b || temp == c; */
  int max = FindMax(a, temp);
  /*@ assert max >= a && max >= temp; */
  /*@ assert max == a || max == temp; */
  /*@ assert temp >= b && temp >= c; */
  /*@ assert max >= a && max >= b && max >= c; */
  /*@ assert (max == a) || (max == temp && (temp == b || temp == c)); */
  /*@ assert (max == a) || (max == b) || (max == c); */
  return max;  // Dafny implicit return
}